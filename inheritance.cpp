#include<iostream>
using namespace std;

class Base {
    private:
        int privateVar;
    protected:
        int protectedVar;
    public:
        int publicVar;  
};

class PublicDerived : public Base {
    // private remains private
    // protected remains protected
    // public remains public
};

class ProtectedDerived : protected Base {
    // private remains private
    // protected remains protected
    // public becomes protected
};

class PrivateDerived : private Base {
    // private remains private
    // protected becomes private
    // public becomes private
    void print() {
        
        cout << protectedVar;
        cout << publicVar;
    }
};


class A {
    public:
    int numA=10;
    void print() {
        cout << numA;
    }
};
class B {
    public:
    int numB = 11;
    void print(int x) {
        cout << numB;
    }
};

class AB : public A, public B {
    
}

int main()
{

    AB o;
    o.print(5);
    
    return 0;
}