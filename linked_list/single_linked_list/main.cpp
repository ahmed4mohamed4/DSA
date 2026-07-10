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

/**
 * @class linkedList
 * @brief A Single Linked List implementation
 * 
 * @member head : Node* - The head pointer of the linked list (default = nullptr)
 * 
 * @method is_empty() : bool
 *         Check if the linked list is empty or not
 * 
 * @method display() : void
 *         Display the entire linked list
 * 
 * @method len() : int
 *         Return the length of the linked list
 * 
 * @method sum() : int
 *         Return the sum of all elements in the linked list
 * 
 * @method max() : int
 *         Find the maximum element in the linked list (returns 0 if empty)
 * 
 * @method min() : int
 *         Find the minimum element in the linked list (returns 0 if empty)
 * 
 * @method contains(const int &target) : bool
 *         Search for a value in the linked list
 *         Returns true if found, false otherwise
 * 
 * @method search(const int &target) : Node*
 *         Return a pointer to the node if found, otherwise return nullptr
 * 
 * @method searchMTF(const int &target) : Node*
 *         Search for a node. If found, move it to the front and return its pointer.
 *         Otherwise, return nullptr (Move-To-Front strategy)
 * 
 * @method insertFront(const int &value) : void
 *         Insert a new node with the given value at the beginning of the linked list
 * 
 * @method insertBack(const int &value) : void
 *         Insert a new node with the given value at the end of the linked list
 * 
 * @method insertAfterGivenValue(const int &target) : void
 *         Insert a new node with the given value after the first occurrence of the target value in the linked list
 * 
 * @method insertAfterGivenNode(Node *given_node, const int &value) : void
 *        Insert a new node with the given value after the specified node
 */
class linkedList {
private:
    Node *head; // The head of linked list

public:
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

    bool contains (const int &target) const { // search for a value in the linked list and return true if found, false otherwise
        Node *temp = head;

        while (temp) {
            if (temp->value == target) {
                return true;
            }
            temp = temp->ptr;
        }

        return false;
    }

    Node* search (const int &target) const { // Return a pointer to the node if found, otherwise return nullptr.
        Node *temp = head;

        while (temp) {
            if (temp->value == target) {
                return temp;
            }
            temp = temp->ptr;
        }

        return nullptr;
    }

    Node* searchMTF (const int &target) { // Search for a node. If found, move it to the front and return its pointer. Otherwise, return nullptr.
        Node *temp = head;
        Node *prev = nullptr;

        while (temp) {
            if (temp->value == target) {
                if (!prev) { // already at front
                    return temp;
                }
                prev->ptr = temp->ptr;
                temp->ptr = head;
                head = temp;
                return temp;
            }
            prev = temp;
            temp = temp->ptr;
        }

        return nullptr;
    }

    void insertFront (const int &value) { // Insert a new node with the given value at the beginning of the linked list.
        Node *new_node = new Node (value);
        new_node->ptr = head;
        head = new_node;
    }

    void insertBack (const int &value) { // Insert a new node with the given value at the end of the linked list.
    
        
        if (is_empty ()) {
            insertFront (value);
            return;
        }

        Node *new_node = new Node (value);
        Node *temp = head;

        while (temp->ptr) {
            temp = temp->ptr;
        }

        new_node->ptr = temp->ptr;
        temp->ptr = new_node;
    }

    void insertAfterGivenValue (const int &target, const int &value) { // Insert a new node with the given value after the first occurrence of the target value in the linked list

        Node *temp = head;

        while (temp && temp->value != target ) {
            temp = temp->ptr;
        }

        if (!temp) {
            return;
        }

        Node *new_node = new Node (value);
        new_node->ptr = temp->ptr;
        temp->ptr = new_node;

    }

    void insertAfterGivenNode (Node *given_node, const int &value) { // Insert a new node with the given value after the specified node
        if (!given_node) {
            return;
        }
        Node *new_node = new Node (value);
        new_node->ptr = given_node->ptr;
        given_node->ptr = new_node;
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
    linkedList linked_list;

    // Build list: 5 -> 10 -> 15 -> 20
    linked_list.insertFront (20);
    linked_list.insertFront (15);
    linked_list.insertFront (10);
    linked_list.insertFront (5);

    linked_list.display ();

    cout << "Length: " << linked_list.len () << '\n';
    cout << "Sum: " << linked_list.sum () << '\n';
    cout << "Max: " << linked_list.max () << '\n';
    cout << "Min: " << linked_list.min () << '\n';

    int targets[] = {15, 7};
    for (int t : targets) {
        cout << "Contains " << t << "? " << (linked_list.contains (t) ? "Yes" : "No") << '\n';
    }

    // search
    Node *found = linked_list.search (10);
    cout << "search (10): " << (found ? to_string (found->value) : string ("not found")) << '\n';

    // search move-to-front
    cout << "Before searchMTF (15): "; linked_list.display ();
    Node *moved = linked_list.searchMTF (15);
    cout << "searchMTF (15) returned: " << (moved ? to_string (moved->value) : string ("not found")) << '\n';
    cout << "After searchMTF (15): "; linked_list.display ();

    // Test insertFront
    cout << "\nTesting insertFront (3): ";
    linked_list.insertFront (3);
    linked_list.display ();

    // Test insertBack
    cout << "Testing insertBack (25): ";
    linked_list.insertBack (25);
    linked_list.display ();

    return 0;
}