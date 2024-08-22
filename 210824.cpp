#include <iostream>

using namespace std;

int main() {
    int ages[5];
    for(int i = 0; i < 5; ++i) {
        cin >> ages[i];
    }
    for(int i : ages) {
        cout << i << " ";
    }
}