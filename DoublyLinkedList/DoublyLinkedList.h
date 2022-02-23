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
  int size;
public:

  DoublyLinkedList(); //post: list is created
  ~DoublyLinkedList(); //pre: list is created, post: all nodes freed

  void insertItem(T &item);
  void deleteItem(T &item);
  void lengthIs() const; //pre: list exists, post: returns the lenght
  void print(); //prints list to stdout
  void printReverse(); //prints list to stdout in reverse
  
} //DoublyLinkedList<>
  
#endif
