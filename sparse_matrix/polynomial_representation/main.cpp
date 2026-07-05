#include <iostream>
#include <cmath>

using namespace std;

struct Term {
    int coefficient; 
    int exponential;
};

struct Polynomial {
    int n; // number of terms
    Term *arr; // array of terms
};

Polynomial createPolynomial () {
    Polynomial p;

    cout << "Number of non-zero terms: ";
    cin >> p.n;

    p.arr = new Term [p.n];

    cout << "(Coefficient, Exponential)\n";
    for (int i = 0; i < p.n; i++) {
        cin >> p.arr [i].coefficient >> p.arr [i].exponential;
    }

    return p;
}

double Evaluation (const Polynomial &p) {
    
    int x;
    cout << "X: ";
    cin >> x;

    double result = 0;

    for (int i = 0; i < p.n; i++) {
        result += pow (x, p.arr [i].exponential) * p.arr [i].coefficient;
    }

    return result;
}



int main () {
    
    Polynomial polynomial = createPolynomial ();

    cout << Evaluation (polynomial) << '\n';

    delete [] polynomial.arr;
    
    return 0;
}