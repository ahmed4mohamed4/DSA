/* 
    - FUNCTIONS
        ===> A piece of code which performs a specific task.
        - If you write all the Code inside the main this called: Monolithic programming.
        - If you break a program into smaller pieces of functions this called: Modular programming or Procedural Programming.
*/

#include <iostream>

using namespace std;


// This is called a definition of the function
//            ⬇️
int add (int a, int b /* Parameters */) 
/*
    Body of the function    
        ⬇️
*/
{
    return a + b;
}

int main () {

    int z = add (1, 2 /* Arguments */);

    cout << z << '\n';


    return 0;
}