#include <iostream>
#include <iomanip>


using namespace std;

// Operators


int main() {
    // Arithmetic Operators + - * / % ++ --;
    int a = 9;
    int b = 12;
    cout << a++ << endl; // post increment
    cout << ++a << endl; // pre increment

    // Assignment Operators =, +=, -=, *=, /=, 
    // a += b;
    // cout << a << endl;

    // Relational Operators < <= > >= == !=

    cout << (b!=a) << endl; 

    // Logical Operators && || !
    // cout << ((b!=a) && a > b) << endl;
    // cout << ((b==a) || a < b) << endl;

    // Bitwise Operators << >> ~ & | 
    cout << b << endl;
    cout << ~b << endl;

    // Type Conversion - Implicit and Explicit
    float f = 45.2367;
    int x = f; // implicit
    cout << x << endl;

    int x = 23;
    double y = (double)x;
    cout << y;
}