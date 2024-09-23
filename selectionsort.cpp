#include<iostream>
#include<vector>

using namespace std;

int findMinIndex(vector<int> array, int start) {
    int minIndex = start;
    for(int i = start; i < array.size(); ++i) {
        if(array.at(i) < array.at(minIndex)) {
            minIndex = i;
        }
    }
    return minIndex;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(vector<int>& array) {
    for(int i = 0; i < array.size() - 1; ++i) {
        int minIndex = findMinIndex(array, i+1);
        if(array.at(minIndex) < array.at(i)) {
            swap(array.at(minIndex), array.at(i));
        }
    }
}

int main()
{    
    vector<int> array = {95, 34, 76, 23, 88, 12, 57, 83, 44, 61, 29, 100, 5, 17, 63, 91, 38, 74, 19, 86, 54, 3, 72, 45, 89, 22, 67, 30, 8, 81, 13, 47, 92, 40, 27, 59, 14, 53, 99, 7};
    selectionSort(array);
    for(int i : array) {
        cout << i <<" ";
    }
    return 0;
}