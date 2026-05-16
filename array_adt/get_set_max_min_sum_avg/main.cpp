#include <iostream>
#include <algorithm>

using namespace std;

struct Array {
    int *A;
    int size;
    int length;
};

bool is_valid_index (const Array &arr, int index) {
    return index >= 0 && index < arr.length;
}

void display (Array &arr) {
    for (int i = 0; i < arr.length; i++) { // O(n)
        cout << arr.A [i] << " ";
    }
    cout << endl;
}

int get (const Array &arr, const int index) {
    if (is_valid_index(arr, index)) {
        return arr.A [index];
    }
    else {
        cout << "Index out of range.\n";
        return 0;
    }
}

void set_value (Array &arr, const int value, const int index) {
    if (is_valid_index(arr, index)) {
        arr.A [index] = value;
    }
    else {
        cout << "Index out of range.\n";
    }
}

int max_value (const Array &arr) {
    if (arr.length) {
        int max_element = arr.A [0];
        for (int i = 1; i < arr.length; i++) {
            max_element = std::max(max_element, arr.A [i]);
        }
        return max_element;
    }
    else {
        cout << "Empty array.\n";
        return 0;
    }
}

int min_value (const Array &arr) {
    if (arr.length) {
        int min_element = arr.A [0];
        for (int i = 1; i < arr.length; i++) {
            min_element = std::min (min_element, arr.A [i]);
        }
        return min_element;
    }
    else {
        cout << "Empty array.\n";
        return 0;
    }
}

int sum_values (const Array &arr) {
    int total = 0;

    for (int i = 0; i < arr.length; ++i) {
        total += arr.A [i];
    }

    return total;
} 

int sum_values_with_recursion (const Array &arr, int n) {
    if (n < 0) {
        return 0;
    }
    
    return sum_values_with_recursion (arr, n - 1) + arr.A [n];
}

double avg (const Array &arr) {
    if (arr.length) {
        return (double) sum_values (arr) / arr.length;
    }
    else {
        cout << "Empty array.\n";
        return 0.0;
    }
}

int main () {

    struct Array ar;
    ar.size = 10;
    ar.length = 3;
    ar.A = new int[ar.size]{12, 27, 32};

    display (ar);


    cout << "Testing max_value function:\n";
    int max_val = max_value(ar);
    cout << "Maximum value in array: " << max_val << ".\n";


    cout << "Testing min_value function:\n";
    int min_val = min_value(ar);
    cout << "Minimum value in array: " << min_val << ".\n";


    cout << "Testing sum_values function:\n";
    int sum_val = sum_values(ar);
    cout << "Sum of all values: " << sum_val << ".\n";


    cout << "Testing sum_values_with_recursion function:\n";
    int sum_recursive = sum_values_with_recursion(ar, ar.length - 1);
    cout << "Sum of all values (recursive): " << sum_recursive << ".\n";


    cout << "Testing avg function:\n";
    double average = avg(ar);
    cout << "Average of all values: " << average << ".\n";


    cout << "Testing get function for index 1:\n";
    int get_val = get(ar, 1);
    cout << "Value at index 1: " << get_val << ".\n";


    cout << "Testing set_value function to set index 0 to 99:\n";
    set_value(ar, 99, 0);
    display(ar);

    delete[] ar.A;

    return 0;
}