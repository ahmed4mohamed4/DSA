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

Polynomial addTwoPolynomials (const Polynomial &p1, const Polynomial &p2) {

    Polynomial p3;
    p3.n = p1.n + p2.n; // maximum number of terms
    p3.arr = new Term [p3.n];

    int i = 0, j = 0, k = 0;
    while (i < p1.n && j < p2.n) {
        if (p1.arr [i].exponential > p2.arr [j].exponential) {
            p3.arr [k++] = p1.arr [i++];
        } else if (p1.arr [i].exponential < p2.arr [j].exponential) {
            p3.arr [k++] = p2.arr [j++];
        } else {
            p3.arr [k].coefficient = p1.arr [i].coefficient + p2.arr [j].coefficient;
            p3.arr [k++].exponential = p1.arr [i].exponential;
            i++;
            j++;
        }
    }

    while (i < p1.n) {
        p3.arr [k++] = p1.arr [i++];
    }
    while (j < p2.n) {
        p3.arr [k++] = p2.arr [j++];
    }

    p3.n = k;
    return p3;
}

void displayPolynomial (const Polynomial &p) {
    for (int i = 0; i < p.n; i++) {
        cout << p.arr [i].coefficient << "x^" << p.arr [i].exponential;
        if (i < p.n - 1) {
            cout << " + ";
        }
    }
    cout << '\n';
}

int main () {
    
    Polynomial polynomial = createPolynomial ();

    cout << Evaluation (polynomial) << '\n';

    Polynomial polynomial1 = createPolynomial ();
    Polynomial polynomial2 = createPolynomial ();

    Polynomial polynomial3 = addTwoPolynomials (polynomial1, polynomial2);

    displayPolynomial (polynomial3);

    delete [] polynomial.arr;
    delete [] polynomial1.arr;
    delete [] polynomial2.arr;
    delete [] polynomial3.arr;
    
    return 0;
}