#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
  head = NULL;
  tail = NULL;
  size = 0;
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
    cout << "add0" << endl;
    length++;
  } else if (temp->data >= item) {
    newNode->next = head;
    newNode->next->back = newNode;
    head = newNode;
    cout << "add1" << endl;
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
    cout << "add2" << endl;
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

template class DoublyLinkedList<int>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<std::string>;
