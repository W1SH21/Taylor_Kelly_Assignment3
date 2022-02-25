#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

int main() {

  int i = 0;
  int j = 1;
  int k = 2;
  int l = 3;
  int m = 4;
  int n = 5;
  int o = 6;
  int p = 7;
  int q = 8;
  DoublyLinkedList<int> list = DoublyLinkedList<int>();  
  list.insertItem(i);
  list.insertItem(j);
  list.insertItem(k);
  list.insertItem(l);
  list.insertItem(m);
  list.insertItem(n);
  list.insertItem(o);
  list.insertItem(p);
  list.insertItem(q);
  
  list.swapAlternate();
  list.print();

} //main

