
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

int main () {
    
    Node node_1 = Node (1);

    cout << "Node 1 value: " << node_1.value << '\n';
    
    Node node_2 = Node (2);
    cout << "Node 2 value: " << node_2.value << '\n';
    
    node_1.ptr = &node_2;
    cout << "Node 2 value: " << node_1.ptr->value << '\n';
    
    return 0;
}