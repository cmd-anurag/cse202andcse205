#include <iostream>
#include <vector>
#include <string>


using namespace std;

void displayVector(vector<int> vec) {
        for(int i : vec) {
            cout << i << " ";
        }
        cout << endl;
}

int main() {
    vector<int> myVector = {1, 2, 3, 4, 5};
    myVector.push_back(10);
    
    displayVector(myVector);
    myVector.erase(myVector.begin()+5);
    displayVector(myVector);
    
}