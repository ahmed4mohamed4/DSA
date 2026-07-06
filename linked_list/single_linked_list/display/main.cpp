
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

    /*
    ## Display function
    - if it is empty : empty
    - else : display the whole linked list
    */
    void display () {
        cout << "Linked list: ";

        if (head == nullptr) {
            cout << "Empty\n";
            return;
        }

        Node *temp = head;

        while (temp) {
            cout << temp->value << ' ';
            temp = temp->ptr;
        }
        
        cout << '\n';
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
    linked_list_1.head->ptr->ptr = new Node (3);

    linked_list_1.display ();
    linked_list_2.display ();
    
    return 0;
}