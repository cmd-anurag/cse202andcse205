#include <iostream>
using namespace std;


bool isKeyPresent(int arr[], int key) {
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        if(key==i) {
            return true;
        }
    }
    return false;
}

int main() {

}