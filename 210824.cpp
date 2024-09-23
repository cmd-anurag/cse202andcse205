#include<iostream>
using namespace std;

class Test {

    public:
    int x;
    static int staticvar;

    static int accessStatic();
    int incrementStatic() {
        ++staticvar;
    }
    
};
int Test::staticvar = 0;

int Test::accessStatic() {
    cout << staticvar << " ";
}




int main()
{
    Test o1;
    Test o2;

    o1.incrementStatic();
    o2.incrementStatic();

    o1.accessStatic();
    
    Test::accessStatic();
    cout << Test::staticvar;
    cout << o1.staticvar;

}