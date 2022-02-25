#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template<class T> struct
NodeType {
  T data;
  NodeType<T> *next;
  NodeType<T> *back;
};
template<class T>
class DoublyLinkedList {

private:
  NodeType<T> *head;
  NodeType<T> *tail;
  int length;

public:

  DoublyLinkedList(); //post: list is created
  ~DoublyLinkedList(); //pre: list is created, post: all nodes freed
  
  void insertItem(T &item); //inserts the value <item> sorted in ascending order
  void deleteItem(T &item); //searches the list for item containing item and removes it
  void deleteSubsection(int lbound, int ubound); //deletes items in range lbound <= x <= ubound from the list
  int lengthIs() const; //pre: list exists, post: returns the lenght
  void print(); //prints list to stdout
  void printReverse(); //prints list to stdout in reverse
  void printElem();
  T getMode(); // returns the mode (most common value) in the list
  void swapAlternate(); //exchanges every other node in the list with it's predacessor.
}; //DoublyLinkedList<>
  
#endif
