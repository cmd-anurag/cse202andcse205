#include<iostream>
using namespace std;


// lets try to bypass the execution of main

class GlobalInitializer {
    public:
        GlobalInitializer() {
            cout << "This will be executed, main won't be\n";
            exit(0);
        }
};

GlobalInitializer init;

int main()
{
    cout << "This won't be executed";
    return 0;
}