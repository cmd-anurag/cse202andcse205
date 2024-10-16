#include <iostream>

using namespace std;

class Base {
    public:
    void print() {
        cout << "Base class\n";
    }
};

class Derived : public Base {
    public:
    void print() {
        cout << "Derived class\n";
    }
};



int main() {
    int n;

}