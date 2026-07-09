
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

    int max () const { // find the max element in linked list and return 0 if the linked list is empty
        if (is_empty ()) {
            return 0;
        }

        Node *temp = head;
        int max_value = temp->value;
        while (temp) {
            if (temp->value > max_value) {
                max_value = temp->value;
            }
            temp = temp->ptr;
        }
        return max_value;
    }

    int min () const { // find the min element in linked list and return 0 if the linked list is empty
        if (is_empty ()) {
            return 0;
        }

        Node *temp = head;
        int min_value = temp->value;
        while (temp) {
            if (temp->value < min_value) {
                min_value = temp->value;
            }
            temp = temp->ptr;
        }
        return min_value;
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

    linked_list_1.head = new Node (12);
    linked_list_1.head->ptr = new Node (42);
    linked_list_1.head->ptr->ptr = new Node (23);

    cout << "Max: " << linked_list_1.max () << endl;
    cout << "Min: " << linked_list_1.min () << endl;

    return 0;
}