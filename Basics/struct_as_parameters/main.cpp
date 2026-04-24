#include <iostream>

using namespace std;

struct Rectangle {
    int length, width;
};

// by value ===> This will create new object
int calc_area_by_value (Rectangle r) {
    r.length = 11;
    return r.length * r.width;
}

int calc_area_by_ref (Rectangle &r) {
    r.length = 11;
    return r.length * r.width;
}

void change_the_length_by_address (Rectangle *p, int l) {
    p->length = l;
}


void PrintSeparator () { cout << "\n-----------------------------------\n"; }

int main () {

    Rectangle r = {10, 5};

    cout << "Area: " << calc_area_by_value (r) << '\n';
    cout << r.length << '\n'; // Not change
    
    PrintSeparator ();
    
    cout << "Area: " << calc_area_by_ref (r) << '\n';
    cout << r.length << '\n'; // Change
    
    PrintSeparator ();
    
    change_the_length_by_address (&r, 20);
    cout << "Length: " << r.length << '\n'; // Change



    return 0;
}