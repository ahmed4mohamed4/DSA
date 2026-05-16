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

void append (Array &arr, const int element) {
    /*
        - we can add new element at the end of the array if there is space available.
    */

    // Add element
    if (arr.length < arr.size) { // O(1)
        arr.A [arr.length] = element;
        arr.length++;
    } else {
        cout << "Array is full. Cannot add new element.\n";
    }
}

void insert (Array &arr, const int index, const int v) {
    /*
        - We can insert an element if the index is between 0 and the length of the array (inclusive).
        - We can insert an element if the length of the array is less than its size.
        - Best case (insert at the end): O(1)
        - Worst case: O(n)
    */

    if (
        index >= 0 &&
        index <= arr.length &&
        arr.length < arr.size
    ) {
       
        for (int i = arr.length; i > index; --i) {
            arr.A [i] = arr.A [i - 1];
        }

        arr.A [index] = v;
        arr.length++;

    } else {
        cout << "Insertion failed. Index is out of bounds or array is full." << endl;
    }
}

void pop (Array &arr) { // O(1)
    if (arr.length > 0) {
        arr.length--;
    }
    else {
        cout << "It is empty!!\n";
    }
}

void remove_at (Array &arr, const int index) {

    // Best case: O(1) (removing the last element)
    // Worst case: O(n) 

    if (arr.length == 0) {
        cout << "It is empty!!!\n";
        return;
    }

    if (
        index >= 0 &&
        index < arr.length
    ) {
        for (int i = index; i < arr.length - 1; i++) { // O(n)
            arr.A [i] = arr.A [i + 1];
        }
        arr.length--;
    }
    else {
        cout << "Index out of range\n";
    }
}

int linear_search (Array &arr, const int key) {
    // Best case: O(1) (if the key is at the first position)
    // Worst case: O(n)
    /*
        Average case: 
            1 + 2 + 3 + 4 + ... + n / n
            (n (n + 1) / 2) / n
            (n + 1) / 2
            O((n + 1) / 2)
    */
    for (int i = 0; i < arr.length; i++) {
        if (arr.A [i] == key) return i;
    }
    return -1;
}

void swap (int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int improve_linear_search_transposition (Array &arr, const int key) {
    for (int i = 0; i < arr.length; i++) {
        if (arr.A [i] == key) {
            if (i > 0) {
                swap (arr.A [i], arr.A [i - 1]); // Transposition
                return i - 1;
            }
            return i;
        }
    }
    return -1;
}

int improve_linear_search_move_to_front (Array &arr, const int key) {
    for (int i = 0; i < arr.length; i++) {
        if (arr.A [i] == key) {
            swap (arr.A [i], arr.A [0]); // Move to front
            return 0;
        }
    }
    return -1;
}

int binary_search (Array &arr, const int key) { // O(log(n + 1)) => O(log n)
    int low = 0;
    int high = arr.length - 1;
    int mid = 0;

    while (low <= high) {
        mid = (low + high) / 2;

        int num = arr.A [mid];

        if (num == key) {
            return mid;
        }
        else if (num < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int binary_search_using_recursion (Array &arr, const int key, int low, int high) {
    int mid = (low + high) / 2;

    if (low <= high) {
        if (arr.A [mid] == key) {
            return mid;
        }
        else if (arr.A [mid] > key) {
            return binary_search_using_recursion (arr, key, low, mid - 1);
        }
        else {
            return binary_search_using_recursion (arr, key, mid + 1, high);
        }
    }

    return -1;
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

void reverse_array (Array &arr) { // O(2n) => O(n)
    Array a;
    a.size = arr.size;
    a.length = arr.length;
    a.A = new int [a.size];

    for (
        int i = arr.length - 1, j = 0;
        i >= 0;
        i--, j++
    ) {
        a.A [j] = arr.A [i];
    }

    for (int i = 0; i < arr.length; i++) {
        arr.A [i] = a.A [i];
    }
}

void reverse_array_with_direct_swap (Array &arr) { // O(n)

    for (
        int i = 0, j = arr.length - 1;
        i < j;
        i++, j--
    ) {
        swap (arr.A [i], arr.A [j]);
    }

}

void print_separator () { cout << "\n===========================\n";}

int main () {
    
    Array arr;
    arr.size = 10;
    arr.length = 3;
    arr.A = new int [arr.size] {43, 98, 13};

    if (arr.length > 0) {
        cout << "First element in the array: " << arr.A[0] << '\n';
    } else {
        cout << "Array is empty; there is no first element.\n";
    }

    print_separator();

    cout << "Current array contents:\n";
    display(arr);

    print_separator();

    cout << "Appending value 111 to the array.\n";
    append(arr, 111);
    display(arr);

    print_separator();

    cout << "Inserting value 77 at index 1.\n";
    insert(arr, 1, 77);
    display(arr);

    print_separator();

    cout << "Removing the last element from the array.\n";
    pop(arr);
    display(arr);

    print_separator();

    cout << "Removing the element at index 2.\n";
    remove_at(arr, 2);
    display(arr);

    print_separator();

    cout << "Linear search for value 13:\n";
    int the_search = linear_search(arr, 13);
    if (the_search == -1) {
        cout << "Value 13 not found.\n";
    } else {
        cout << "Value 13 found at index " << the_search << ".\n";
    }

    print_separator();

    cout << "Improved linear search (transposition) for value 13:\n";
    int the_search2 = improve_linear_search_transposition(arr, 13);
    if (the_search2 == -1) {
        cout << "Value 13 not found.\n";
    } else {
        cout << "Value 13 found at index " << the_search2 << ".\n";
    }

    print_separator();

    cout << "Improved linear search (move to front) for value 13:\n";
    int the_search3 = improve_linear_search_move_to_front(arr, 13);
    if (the_search3 == -1) {
        cout << "Value 13 not found.\n";
    } else {
        cout << "Value 13 found at index " << the_search3 << ".\n";
    }

    print_separator();

    struct Array ar;
    ar.size = 10;
    ar.length = 3;
    ar.A = new int[ar.size]{12, 27, 32};

    cout << "Binary search for value 27:\n";
    int x = binary_search(ar, 27);
    if (x == -1) {
        cout << "Value 27 not found.\n";
    } else {
        cout << "Value 27 found at index " << x << ".\n";
    }

    print_separator ();

    cout << "Binary search using recursion for value 32:\n";
    int y = binary_search_using_recursion(ar, 32, 0, ar.length - 1);
    if (y == -1) {
        cout << "Value 32 not found.\n";
    } else {
        cout << "Value 32 found at index " << y << ".\n";
    }

    print_separator ();

    cout << "Testing max_value function:\n";
    int max_val = max_value(ar);
    cout << "Maximum value in array: " << max_val << ".\n";

    print_separator();

    cout << "Testing min_value function:\n";
    int min_val = min_value(ar);
    cout << "Minimum value in array: " << min_val << ".\n";

    print_separator();

    cout << "Testing sum_values function:\n";
    int sum_val = sum_values(ar);
    cout << "Sum of all values: " << sum_val << ".\n";

    print_separator();

    cout << "Testing sum_values_with_recursion function:\n";
    int sum_recursive = sum_values_with_recursion(ar, ar.length - 1);
    cout << "Sum of all values (recursive): " << sum_recursive << ".\n";

    print_separator();

    cout << "Testing avg function:\n";
    double average = avg(ar);
    cout << "Average of all values: " << average << ".\n";

    print_separator();

    cout << "Testing get function for index 1:\n";
    int get_val = get(ar, 1);
    cout << "Value at index 1: " << get_val << ".\n";

    print_separator();

    cout << "Testing set_value function to set index 0 to 99:\n";
    set_value(ar, 99, 0);
    display(ar);

    print_separator();

    reverse_array (ar);

    display (ar);

    print_separator ();

    cout << "Testing reverse_array_with_direct_swap function:\n";
    reverse_array_with_direct_swap (ar);
    display (ar);

    print_separator ();

    delete[] arr.A;
    delete[] ar.A;

    return 0;
}