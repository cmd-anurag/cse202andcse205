#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

class Bulb {
    bool turnedON;
    friend class Phone;
    public:
    Bulb() : turnedON(false) {};
};

class Phone {
    string name;

    public:
    void turnOnBulb(Bulb& bulb) {
        bulb.turnedON = true;
        cout << "Bulb turned on successfully\n";
    }
};



int main()
{
    Bulb b1;
    Phone p1;

    p1.turnOnBulb(b1);

}