#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

int main() {

  int i = 10;
  int j = 11;
  int k = 9;
  DoublyLinkedList<int> list = DoublyLinkedList<int>();  
  list.insertItem(i);
  list.insertItem(j);
  list.insertItem(k);

  list.deleteItem(k);
  
  list.printReverse();
  

} //main

