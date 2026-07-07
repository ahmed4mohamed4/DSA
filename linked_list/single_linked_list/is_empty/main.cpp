
#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node *ptr;
    Node (int v = 0) {
        this->value = v;
        this->ptr = nullptr;
    }
};

class linkedList {
public:
    Node *head;

    linkedList () { // constructor
        this->head = nullptr;
    }

    bool is_empty () const {
        return !head;
    }
    
    ~linkedList () { // destructor
        Node *temp = head;

        while (temp) {
            Node *next = temp->ptr;
            delete temp;
            temp = next;
        }
    }
};

int main () {

    linkedList l;
    linkedList l2;

    l.head = new Node (1);

    cout << l.is_empty () << endl;
    cout << l2.is_empty () << endl;
    
    return 0;
}