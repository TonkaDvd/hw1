/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
#include <string>
using namespace std;
#include <cstddef>

void makeDummyLinkedList(Node*& in, int Endvalue, int Startvalue){
    if(Startvalue == Endvalue + 1){
        return;
    } else{
        in = new Node(Startvalue, NULL);
        return makeDummyLinkedList(in->next, Endvalue, Startvalue + 1);
    }
}

void printList(const string& name, Node* head) {
    cout << name << ": ";
    while (head != nullptr) {
        cout << head->value << " -> ";
        head = head->next;
    }
    cout << "nullptr\n";
}

int main(int argc, char* argv[])
{
    Node* in = nullptr;
    Node* evens = nullptr; 
    Node* odds = nullptr;

    makeDummyLinkedList(in, 11, 1);
    split(in, odds, evens);

    printList("Odds", odds);
    printList("Evens", evens);
}
