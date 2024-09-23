#include<iostream>
using namespace std;

void insertionSort(int array[], int n) {
    for(int i = 1; i < n; ++i) {
        int element = array[i];
        int j = i;
        while(j > 0 && element < array[j-1]) {
            array[j] = array[j-1];
            j--;
        }
        array[j] = element;
    }
}

int main()
{
    int array[7] = {7, 6, 1, 9, 2, 4, 3};
    insertionSort(array, 7);
    for(int i : array) {
        cout << i <<" ";
    }
    return 0;
}