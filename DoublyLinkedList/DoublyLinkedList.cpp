#include "DoublyLinkedList.h"
#include <iostream>


DoublyLinkedList<T>::DoublyLinkedList() {
  head = NULL;
  tail = NULL;
  size = 0;
} //DoublyLinkedList

DoublyLinkedList<T>::~DoublyLinkedList() {
  NodeType<T>* temp = head; 
  while (temp->next != NULL) {
    NodeType<T>* del = temp;
    temp = temp->next;
    delete[] del;
  } //while
} //~DoublyLinkedList

void DoublyLinkedList<T>::insertItem(T &item) {
  NodeType<T>* temp = head;
  NodeType<T>* newNode = new NodeType<T>;
  newNode->data = item;
  if (temp == NULL) {
    temp = newNode;
    length++;
  } else if (temp->data >= item) {
    newNode->next = temp;
    newNode->next->back = newNode;
    temp = newNode;
    length++;
  } else {
    
    while (temp->next != NULL && temp->next->data < item) {
      temp = temp->next;
    } //while
    
    newNode->next = temp->next;
    if (temp->next != NULL) {
      newNode->next->back = newNode;
    } //if
    temp->next = newNode;
    newNode->back = temp;
    length++;
  } //if
} //insertItem


void DoublyLinkedList<T>::deleteItem(T &item) {
  NodeType<T> temp = head;

  while (temp->next != NULL && temp->data != item) {
    temp = temp->next;
  } //while

  temp->back->next = temp->next;
  temp->next->back = temp->back;
  length--;
} //deleteItem


int DoublyLinkedList<T>::lengthIs() const {
  return size;
} //lengthIs

void DoublyLinkedList<T>::print() {
  NodeType<T> temp = head;
  while (temp->next != NULL) {
    cout << temp->data + " " << endl;
    temp = temp->next;
  } //while
} //print


void DoublyLinkedList<T>::printReverse() {
  NodeType<T> temp = tail;
  while (temp->back != NULL) {
    cout << temp->data + " " << endl;
    temp = temp->back
  } //while
} //printReverse
