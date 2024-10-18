#include <iostream>

using namespace std;

#include <iostream>
using namespace std;

class ParentX {
protected:
    int x;
public:
    ParentX() : x(19) {}
};

class ChildY : public ParentX {
public:
    int y;
    
    ChildY() : y(20) {};
    void f() {
        x
    }
};

int main() {
    ParentX* ptr = new ChildY();
    // cout << ptr->x << ", " << ptr->y;
    return 0;
}


