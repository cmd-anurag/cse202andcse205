#include<iostream>
using namespace std;

template <typename T>
class Base {
    public:
        T value;
    
};

template <typename T>
class Derived : public Base<int> {
    public:
        T derivedValue;
};


int main()
{   
    Derived<float> obj;
    obj.value = 12;
    obj.derivedValue = 13.45;
    cout << obj.value;
    return 0;
}