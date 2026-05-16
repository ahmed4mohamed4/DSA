#include <iostream>

using namespace std;

struct Rectangle {
    int length = 4, width = 3;
};

void PrintSeparator () { cout << "\n----------------------------\n"; }

int main () {

    Rectangle r = {2, 3};
    Rectangle *ptr = &r;

    // Accessing these member using the pointers

    cout << "Length: " << (*ptr).length << "\nWidth: " << (*ptr).width << '\n';
    
    PrintSeparator ();
    
    cout << "Length: " << ptr->length << "\nWidth: " << ptr->width << '\n';
    
    PrintSeparator ();
    
    // Create dynamic pointer in heap
    
    Rectangle *p;
    
    // p = (Rectangle *)malloc (sizeof (Rectangle)); In C++, prefer new over malloc because new calls the constructor and is type safe
    p = new Rectangle;
    
    p->length = 10;
    p->width = 15;
    
    cout << "Length: " << p->length << "\nWidth: " << p->width << '\n';

    delete p;



    return 0;
}