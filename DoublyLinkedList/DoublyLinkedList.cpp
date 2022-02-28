#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
  head = NULL;
  tail = NULL;
  length = 0;
} //DoublyLinkedList


template<class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
  NodeType<T>* temp = head; 
  while (temp != NULL) {
    NodeType<T>* del = temp;
    temp = temp->next;
    delete[] del;
  } //while
} //~DoublyLinkedList


template<class T>
void DoublyLinkedList<T>::insertItem(T &item) {
  NodeType<T>* temp = head;
  NodeType<T>* newNode = new NodeType<T>;
  newNode->data = item;
  if (temp == NULL) {
    head = newNode;
    tail = newNode;
    newNode->next = NULL;
    length++;
  } else if (temp->data >= item) {
    newNode->next = head;
    newNode->next->back = newNode;
    head = newNode;
    length++;
  } else {
    
    while (temp->next != NULL && temp->next->data < item) {
      temp = temp->next;
    } //while
    
    newNode->next = temp->next;
    if (temp->next != NULL) {
      newNode->next->back = newNode;
    } else {
      tail = newNode;
    } //if
    temp->next = newNode;
    newNode->back = temp;
    length++;
  } //if
} //insertItem

template<class T>
void DoublyLinkedList<T>::deleteItem(T &item) {
  NodeType<T>* temp = head;

  while (temp->next != NULL && temp->data != item) {
    temp = temp->next;
  } //while

  if (temp->back != NULL) {
    temp->back->next = temp->next;
  } else {
    head = head->next;
  } //if
  
  if (temp->next != NULL) {
    temp->next->back = temp -> back;
  } else {
    tail = tail->back;
  } //if
  length--;
} //deleteItem

template<class T>
int DoublyLinkedList<T>::lengthIs() const {
  return length;
} //lengthIs

template<class T>
void DoublyLinkedList<T>::print() {
  NodeType<T>* temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  } //while
  cout << endl;
} //print

template<class T>
void DoublyLinkedList<T>::printReverse() {
  NodeType<T>* temp = tail;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->back;
  } //while
  cout << endl;
} //printReverse

template<class T>
void DoublyLinkedList<T>::printElem() {
  cout << tail->data << endl;
}//printElem

template<class T>
void DoublyLinkedList<T>::deleteSubsection(int lbound, int ubound) {
  if (head == NULL || ubound < 0 || ubound > length - 1 || lbound < 0 || lbound > length - 1) {
    cout << "Invalid Range" << endl;
  } else {
    NodeType<T>* lowerBound = head;
    NodeType<T>* upperBound = tail;

    for (int i = 0; i < lbound; i++) {
      lowerBound = lowerBound->next;
    } //for
      
    for (int i = length - 1; i > ubound; i--) {
      upperBound = upperBound->back;
    } //for

    
    if (lbound != 0 && ubound != length - 1) {

      upperBound->next->back = lowerBound->back;
      lowerBound->back->next = upperBound->next;

      //frees all deleted nodes (re-uses upperBound to hold the addresses of nodes to be deleted)
      for (int i = lbound; i < ubound; i++) {
        upperBound = lowerBound;
	lowerBound = lowerBound->next;
	delete [] upperBound;
      } //for
      
    } else {
      
      if (ubound == length - 1 && lbound == 0) {
	head = NULL;
	tail = NULL;
      } else if (ubound == length - 1) {
	tail = lowerBound->back;
	lowerBound->back->next = NULL;
	
	for (int i = lbound; i < ubound; i ++) {
	  upperBound = lowerBound;
	  lowerBound = lowerBound->next;
	  delete[] upperBound;
	} //for
	
      } else if (lbound == 0) {
	head = upperBound->next;

	for (int i = lbound; i < ubound; i++) {
	  upperBound = lowerBound;
	  lowerBound = lowerBound->next;
	  delete[] upperBound;
	} //for
      } //if
    } //if
  } //if
} //deleteSubsection

template<class T>
T DoublyLinkedList<T>::getMode() {
  NodeType<T>* temp = head;
  int appearances = 1;
  NodeType<T>* modeRef;
  
  while (temp->next != NULL) {

    if (temp->data == temp->next->data) {
      appearances++;
      temp = temp->next;
    } else {
      appearances = 1;
      modeRef = temp->back;
      temp = temp->next;
    } //if
  } //while

  return modeRef->data;
} //getMode

template<class T>
void DoublyLinkedList<T>::swapAlternate() {
  if (head == NULL || head->next == NULL) {
    return;
  } //if

  //used two iterators to make implementation simpler and more legible (however it is possible with 1)
  NodeType<T>* temp = head;
  NodeType<T>* tempNext = head->next;
  bool reachedEnd = false;

  tempNext->next->back = temp;
  temp->next = tempNext->next;
  tempNext->back = NULL;
  temp->back = tempNext;
  tempNext->next = temp;
  head = tempNext;
  
  while (!reachedEnd) {

    if ((tempNext->next->next->next != NULL) && !reachedEnd) {
      tempNext = tempNext->next->next->next;
      temp = temp->next;
    } else {
      reachedEnd = true;
    } //if
    
    if (tempNext->next->next == NULL) {
      reachedEnd = true;
    } //if
    temp->back->next = tempNext;
    tempNext->next->back = temp;
    temp->next = tempNext->next;
    tempNext->back = temp->back;
    temp->back = tempNext;
    tempNext->next = temp;  
  } //while
} //swapAlternate

template<class T>
bool DoublyLinkedList<T>::searchItem(T &item) {
    NodeType<T>* temp = head;
    while (temp->next != NULL) {
        if (temp->data == item) {
            return true;
        }
        temp = temp->next;
    } // while
    return false;
} //searchItem

template<class T>
int DoublyLinkedList<T>::findFirstIndex(T &item) {
  NodeType<T>* temp = head;
  int i = 0;

  if (item < head->data) {
    i = 0;
  } else if (item > tail->data) {
    i = length - 1;
  } else {
    while (temp->next != NULL && temp->data < item) {
      temp = temp->next;
      i ++;
    } //while
  } //if
    
  return i; 
} //findNode

template class DoublyLinkedList<int>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<std::string>;
