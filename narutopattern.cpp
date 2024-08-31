#include <iostream>


using namespace std;

int main() {
    int array[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};    
    
    int TR = 0;
    int BR = 3;
    int LC = 0;
    int RC = 3;

    while (TR < BR && LC<RC)
    {
        for(int i = LC; i <= RC; ++i) {
            cout << array[TR][i] << " ";
        }
        TR++;
        for(int i = TR; i <= BR; i++) {
            cout << array[i][RC] << " ";
        }
        RC--;
        for(int i = RC; i>=LC; i--) {
            cout << array[BR][i] << " ";
        }
        BR--;
        for(int i = BR; i>=TR; --i) {
            cout << array[i][LC] << " ";
        }
        LC++;
    }
    
    
}