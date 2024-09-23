#include<iostream>
using namespace std;

class Rectangle {
    int length;
    int breadth;
    public:
        Rectangle(int l, int b) : length(l), breadth(b) {}

        int getArea() {
            return length*breadth;
        }
        int getLength() {
            return length;
        }
        void setLength(int l) {
            length = l;
        }
        int getBreadth() {
            return breadth;
        }
        void setBreadth(int b) {
            breadth = b;
        }
};

int main()
{
    
    return 0;
}