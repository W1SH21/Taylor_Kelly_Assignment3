compile: main.o DoublyLinkedList.o
	g++ -Wall -pedantic-errors -o main main.o DoublyLinkedList.o

main.o: main.cpp DoublyLinkedList.h
	g++ -Wall -pedantic-errors -c -g main.cpp

DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.h
	g++ -Wall -pedantic-errors -c -g DoublyLinkedList.cpp

clean:
	rm -f main
	rm -f *.o
