#include<iostream>
using namespace std;

void bubbleSort(int array[], int n) {
    bool swapped = false;
    for(int i = 0; i < n; ++i) {
        swapped = false;
        for(int j = 0; j < n - 1; ++j) {
            if(array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}

int main()
{
    int arr[7] = {3, 6, 1, 4, 7, 12, 2};
    bubbleSort(arr, 7);
    for(int i : arr) {
        cout << i << " ";
    }
    return 0;
}