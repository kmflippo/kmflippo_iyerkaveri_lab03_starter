// intlist.cpp
// Implements class IntList
// Kelly Flippo, Kaveri Iyer, 1/27/2022

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    //IMPLEMENT THIS
    first = nullptr;
    Node* temp = source.first;

    while (temp != nullptr) {
        append(temp->info);
        temp = temp->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {

    Node *temp = first;
    Node *iterate = temp->next;
    while(temp->next != nullptr){
        delete temp;
        temp = iterate;
        iterate = temp->next;
    }
    delete temp;
}


// return sum of values in list
int IntList::sum() const {
    int result = 0;
    Node *n = first;
    while (n) {
        result = result + n->info;
        n = n->next;
    }
    return result; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node *n = first;
    while (n){
        if (n->info == value){
            return true;
        }
        n = n->next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    Node *n = first;

    if (!n) {
        return 0;
    }

    int max = first->info;
    while (n) {
        if (max < n->info) {
            max = n->info;
        }
        n = n->next;
    }
    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    Node *n = first;
    if (!n){
        return 0;
    }
    
    int listSum = sum();
    int listLength = 0;
    
    while (n){
        listLength++;
        n = n-> next;
    }
    double avg = ((double)listSum)/listLength;
    return avg;
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    // IMPLEMENT
    Node *n = new Node;
    n->info = value;
    n->next = first;
    first = n;
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this != &source){
        
        /*Node *temp = first;
        while(temp->next != nullptr){
            first = first->next;
            delete temp;
            temp = first;
        }*/

        first = nullptr;
        Node* temp2 = source.first;

        while (temp2 != nullptr) {
            append(temp2->info);
            temp2 = temp2->next;
        }
    }

    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
