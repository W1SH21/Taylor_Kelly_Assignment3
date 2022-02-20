#include "DoublyLinkedList.h"
#include <iostream>


DoublyLinkedList<T>::DoublyLinkedList() {
  head = NULL;
  tail = NULL;
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
  NodeType<T>* newNode;
  newNode->data = item;
  
  if (temp == NULL) {
    temp = newNode;
  } else if (temp->data >= newNode->data) {
    newNode->next = temp;
    newNode->next->back = newNode;
    temp = newNode;
  } else {

    while (temp->next != NULL &&
	   temp->next->data < newNode->data) {
      temp = temp->next;
    } //while
    
    newNode->next = temp->next;
    if (temp->next != NULL) {
      newNode->next->back = newNode;
    } //if
    temp->next = newNode;
    newNode->back = temp;
  } //if
} //insertItem


  
