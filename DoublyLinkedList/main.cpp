#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "DoublyLinkedList.h"

using namespace std;

int main(int argc, char* argv[]) {
    string fix;
    while (true) {
        cout << "Enter list type (i - int, f - float, s - std::string) : ";
        string type;
        cin >> type;
        ifstream fin;
        fin.open(argv[1]); // read input file
        if (type == "i") {
            DoublyLinkedList<int> list = DoublyLinkedList<int>();
            int num;
            while (fin >> num) {
                list.insertItem(num);
            }   
            getline(cin, fix);
            fin.close();
            while (true) {
                string uinput;
                cout << "insert (i), ";
                cout << "delete (d), ";
                cout << "length (l), ";
                cout << "print (p), ";
                cout << "deleteSub (b), ";
                cout << "mode (m), " << endl;
                cout << "printReverse (r), swapAt1(s), ";
                cout << "quit (q)" << endl;
                cout << "Enter a command: ";
                getline(cin, uinput);
                cout << endl;
                if (uinput == "i") {
                    int input;
                    cout << "Item to insert: ";
                    cin >> input;
                    getline(cin, fix);
                    cout << endl;
                    list.insertItem(input);
                    list.print();
                } else if (uinput == "d") {
                    int input;
                    cout << "Item to delete: ";
                    cin >> input;
                    getline(cin, fix);
                    cout << endl;
                    if (list.lengthIs() == 0) {
                        cout << "You cannot delete from an empty list." << endl;
                    } else {
                        if (list.searchItem(input)) {
                            list.deleteItem(input);
                            list.print();
                        } else {
                            cout << "Item not in list!" << endl;
                            list.print();
                        } // if
                    } // if
                } else if (uinput == "l") {
                    cout << "The length is: " << list.lengthIs() << endl;
                } else if (uinput == "p") {
                    list.print();
                } else if (uinput == "b") {
                    int low, up;
                    cout << "Enter lower bound: ";
                    cin >> low;
                    getline(cin, fix);
                    cout << endl;
                    cout << "Enter upper bound: ";
                    cin >> up;
                    getline(cin, fix);
                    cout << endl;
                    cout << "Original List: ";
                    list.print();
                    cout << endl;
		    low = list.findFirstIndex(low);
		    up = list.findFirstIndex(up);
                    list.deleteSubsection(low, up);
                    cout << "Modified List: ";
                    list.print();
                    cout << endl;
                } else if (uinput == "m") {
                    list.print();
                    cout << "Mode: " << list.getMode() << endl;
                } else if (uinput == "r") {
                    list.printReverse();
                } else if (uinput == "s") {
                    cout << "Original List: ";
                    list.print();
                    cout << endl;
                    list.swapAlternate();
                    cout << "Swapped list: ";
                    list.print();
                    cout << endl;
                } else if (uinput == "q") {
                    return 0;
                } else {
                    cout << "Invalid command, try again!" << endl;
                } // read user input
            } // command line input loop
        } else if (type == "f") {
            DoublyLinkedList<float> list = DoublyLinkedList<float>();
            float num;
            while (fin >> num) {
                list.insertItem(num);
            }
            getline(cin, fix);
            fin.close();
            while (true) {
                string uinput;
                cout << "insert (i), ";
                cout << "delete (d), ";
                cout << "length (l), ";
                cout << "print (p), ";
                cout << "deleteSub (b), ";
                cout << "mode (m), " << endl;
                cout << "printReverse (r), swapAt1(s), ";
                cout << "quit (q)" << endl;
                cout << "Enter a command: ";
                getline(cin, uinput);
                cout << endl;
                if (uinput == "i") {
                    float input;
                    cout << "Item to insert: ";
                    cin >> input;
                    getline(cin, fix);
                    cout << endl;
                    list.insertItem(input);
                    list.print();
                } else if (uinput == "d") {
                    float input;
                    cout << "Item to delete: ";
                    cin >> input;
                    getline(cin, fix);
                    cout << endl;
                    if (list.lengthIs() == 0) {
                        cout << "You cannot delete from an empty list." << endl;
                    } else {
                        if (list.searchItem(input)) {
                            list.deleteItem(input);
                            list.print();
                        } else {
                            cout << "Item not in list!" << endl;
                            list.print();
                        } // if
                    } // if
                } else if (uinput == "l") {
                    cout << "The length is: " << list.lengthIs() << endl;
                } else if (uinput == "p") {
                    list.print();
                } else if (uinput == "b") {
                    int low, up;
                    cout << "Enter lower bound: ";
                    cin >> low;
                    getline(cin, fix);
                    cout << endl;
                    cout << "Enter upper bound: ";
                    cin >> up;
                    getline(cin, fix);
                    cout << endl;
                    cout << "Original List: ";
                    list.print();
                    cout << endl;
                    list.deleteSubsection(low, up);
                    cout << "Modified List: ";
                    list.print();
                    cout << endl;
                } else if (uinput == "m") {
                    list.print();
                    cout << "Mode: " << list.getMode() << endl;
                } else if (uinput == "r") {
                    list.printReverse();
                } else if (uinput == "s") {
                    cout << "Original List: ";
                    list.print();
                    cout << endl;
                    list.swapAlternate();
                    cout << "Swapped list: ";
                    list.print();
                    cout << endl;
                } else if (uinput == "q") {
                    return 0;
                } else {
                    cout << "Invalid command, try again!" << endl;
                } // read user input
            } // command line input loop
        } else if (type == "s") {
            DoublyLinkedList<string> list = DoublyLinkedList<string>();
            string word;
            while (fin >> word) {
                list.insertItem(word);
            } // while
            getline(cin, fix);
            fin.close();
            while (true) {
                string uinput;
                cout << "insert (i), ";
                cout << "delete (d), ";
                cout << "length (l), ";
                cout << "print (p), ";
                cout << "deleteSub (b), ";
                cout << "mode (m), " << endl;
                cout << "printReverse (r), swapAt1(s), ";
                cout << "quit (q)" << endl;
                cout << "Enter a command: ";
                getline(cin, uinput);
                cout << endl;
                if (uinput == "i") {
                    string input;
                    cout << "Item to insert: ";
                    getline(cin, input);
                    cout << endl;
                    list.insertItem(input);
                    list.print();
                } else if (uinput == "d") {
                    string input;
                    cout << "Item to delete: ";
                    getline(cin, input);
                    cout << endl;
                    if (list.lengthIs() == 0) {
                        cout << "You cannot delete from an empty list." << endl;
                    } else {
                        if (list.searchItem(input)) {
                            list.deleteItem(input);
                            list.print();
                        } else {
                            cout << "Item not in list!" << endl;
                            list.print();
                        } // if
                    } // if
                } else if (uinput == "l") {
                    cout << "The length is: " << list.lengthIs() << endl;
                } else if (uinput == "p") {
                    list.print();
                } else if (uinput == "b") {
                    int low, up;
                    cout << "Enter lower bound: ";
                    cin >> low;
                    getline(cin, fix);
                    cout << endl;
                    cout << "Enter upper bound: ";
                    cin >> up;
                    getline(cin, fix);
                    cout << endl;
                    cout << "Original List: ";
                    list.print();
                    cout << endl;
                    list.deleteSubsection(low, up);
                    cout << "Modified List: ";
                    list.print();
                    cout << endl;
                } else if (uinput == "m") {
                    list.print();
                    cout << "Mode: " << list.getMode() << endl;
                } else if (uinput == "r") {
                    list.printReverse();
                } else if (uinput == "s") {
                    cout << "Original List: ";
                    list.print();
                    cout << endl;
                    list.swapAlternate();
                    cout << "Swapped list: ";
                    list.print();
                    cout << endl;
                } else if (uinput == "q") {
                    exit(0);
                } else {
                    cout << "Invalid command, try again!" << endl;
                } // read user input
            } // command line input loop
        } else {
            cout << "Invalid type. Please enter a valid type." << endl;
        } // if
    } // while
} // main
