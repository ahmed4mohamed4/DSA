#include <iostream>

using namespace std;

/* 
# Node
## for single linked list
- Value : int -> default = 0
- ptr for next node : Node -> default = nullptr
*/
class Node {
public:
    int value;
    Node *ptr;
    Node (int v = 0) {
        this->value = v;
        this->ptr = nullptr;
    }
};

/* # Single Linked list class
    - head : Node -> default = nullptr
    - is_empty () : bool -> check if the linked list is empty or not
    - display () : void -> display the whole linked list
*/
class linkedList {
public:
    Node *head;

    linkedList () { // constructor
        this->head = nullptr;
    }

    bool is_empty () const { // check if the linked list is empty or not
        return !head;
    }

    void display () const { // display the whole linked list
        cout << "Linked list: ";

        if (is_empty ()) {
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
    
    int len () const { // return the length of the linked list
        int counter = 0;

        Node *temp = head;

        while (temp) {
            counter++;
            temp = temp->ptr;
        }
        
        return counter;
    }

    int sum () { // return the sum of all elements in the linked list
        
        int result = 0;

        Node *temp = head;

        while (temp) {
            result += temp->value;
            temp = temp->ptr;
        }

        return result;

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
    
    
    
    return 0;
}