#include<iostream>
using namespace std;

class Test {
    public:
    int x;
    
};

int main()
{
    Test t;
    t.x = 4;
    
    // creating a pointer to a member of a class
    int Test::*ptr = &Test::x;
    cout << t.*ptr;

    // creating a pointer to object
    Test* ptrobj = &t;

    // accessing the member using pointer to object
    
    cout << ptrobj->*ptr;

    return 0;
}