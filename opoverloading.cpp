#include<iostream>
using namespace std;


class Test {
    public:
    int value = 10;

    // basic to class
    Test() {};
    Test(int v) {
        value = v;
    }

    void operator=(int x) {
        value = x;
    }

    // class to basic
    operator int() {
        return value;
    }

    operator string() {
        return "bruh";
    }

    void operator+(int a) {
        value += a;
    }

    Test operator++(int) {
        Test temp = *this;
        ++value;
        return temp;
    }
};


int main()
{
    Test t;
    t++;
    
    cout << t.value;

    // basic to class type
    t = 13;

    cout << '\n' << t.value << '\n';

    string s = t;
    int x = t;

    cout << s << " " << t;

    return 0;
}