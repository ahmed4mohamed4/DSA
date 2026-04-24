#include <iostream>

using namespace std;


// Template class example for arithmetic operations

template <class T>
class Arithmetic {
private:
    T a, b;
public:
    Arithmetic (T a, T b);
    T add ();
    T sub ();
};

template <class T>
Arithmetic<T>::Arithmetic (T a, T b) {
    this->a = a;
    this->b = b;
}

template <class T>
T Arithmetic<T>::add () {
    return a + b;
}

template <class T>
T Arithmetic<T>::sub () {
    return a - b;
}

int main () {

    Arithmetic<int> ar1 (10, 5);

    cout << ar1.add () << '\n';

    Arithmetic <float> ar2 (12.5, 5.3);

    cout << ar2.add () << '\n';
    
    return 0;
}