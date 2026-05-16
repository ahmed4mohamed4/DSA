#include <iostream>

using namespace std;

void PrintSeparator () { cout << "\n--------------------\n";}

struct Rectangle { // The size depend on the data inside.
    int w, h; // Now it is not consuming any memory because it is just a defentanon.
};

struct ComplexNumber { // a + ib
    float real_num;
    float img_num;
    char i;
};



struct Student {
    string name;
    string dept;
    int id;
};

int main () {

    cout << sizeof (Rectangle) << endl; // Has two integer 4 + 4 = 8

    Rectangle r;
    cout << r.w << " | " << r.h << endl;
    r.h = 15;
    r.w = 10;
    cout << r.w << " | " << r.h << endl;
    printf ("Area: %d\n", r.w * r.h);

    PrintSeparator ();

    Student s;
    s.name = "Ahmed";
    s.dept = "AI";
    s.id = 123456;

    cout << "The size of for student struct: " << sizeof (Student) << endl;
    
    Student s2 = {"Mohamed", "Cyber", 654321};
    
    cout << "Name f first student ---> " << s.name << '\n';
    
    PrintSeparator ();
    
    ComplexNumber complex_num [2] = {{2.1 , 3.2, 'i'}, {4.2, 1.8, 'i'}};
    cout << "The size of for ComplexNumber struct: " << sizeof (ComplexNumber) << endl;

    cout << complex_num [1].real_num << endl << sizeof (float);


    return 0;
}