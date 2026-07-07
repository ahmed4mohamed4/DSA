
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

    int len () const {
        int counter = 0;

        Node *temp = head;

        while (temp) {
            counter++;
            temp = temp->ptr;
        }
        
        return counter;
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

    linkedList linked_list_1;
    linkedList linked_list_2;

    linked_list_1.head = new Node (1);
    linked_list_1.head->ptr = new Node (2);

    cout << linked_list_1.len () << '\n';
    cout << linked_list_2.len () << '\n';
    
    return 0;
}