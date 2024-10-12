#include<iostream>
#include<vector>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int findPivotIndex(vector<int> &array, int low, int high) {
    int start = low;
    int end = high;
    int pivotElement = array[low];
    while(start <= end) {
       while(start <= end && array[start] <= pivotElement) ++start;
       while(start <= end && array[end] > pivotElement) --end;
       if(start < end) {
        swap(array[start], array[end]);
       }
    }
    swap(array[end], array[low]);
    return end;
}


void QuickSort(vector<int> &array, int low, int high) {
    if(high > low) {
        int pivotIndex = findPivotIndex(array, low, high);
        QuickSort(array, low, pivotIndex-1);
        QuickSort(array, pivotIndex+1, high);
    }
}



int main()
{
    vector<int> array = {7,2,24,6,2,122,46,3};
    QuickSort(array, 0, array.size()-1);
    for(int i : array) {
        cout << i << " ";
    }
    return 0;
}