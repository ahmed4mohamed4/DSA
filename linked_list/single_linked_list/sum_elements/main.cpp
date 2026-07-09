
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

    int sum () {
        
        int result = 0;

        Node *temp = head;

        while (temp) {
            result += temp->value;
            temp = temp->ptr;
        }

        return result;

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

    linked_list_1.head = new Node (1);
    linked_list_1.head->ptr = new Node (2);
    linked_list_1.head->ptr->ptr = new Node (3);

    cout << "Sum: " << linked_list_1.sum () << '\n';
    
    return 0;
}