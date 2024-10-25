#include<iostream>
#include<vector>


using namespace std;

// merge sort

void merge(vector<int> &array, int start, int middle, int end) {
    vector<int> result(end - start + 1);

    int i = start;
    int j = middle+1;

    int k = 0;

    while(i <= middle && j <= end) {
        if(array[i] < array[j]) {
            result[k++] = array[i++];
        }
        else if(array[j] < array[i]) {
            result[k++] = array[j++];
        }
        else {
            result[k++] = array[i++];
            result[k++] = array[j++];
        }
    }

    while(i <= middle) {
        result[k++] = array[i++];
    }
    while(j <= end) {
        result[k++] = array[j++];
    }

    k = 0;
    for(int i = start; i <= end; ++i) {
        array[i] = result[k++];
    }
}

void mergeSort(vector<int> &array, int start, int end) {
    if(start < end) {
        int middle = (start+end)/2;
        mergeSort(array, start, middle);
        mergeSort(array, middle+1, end);

        merge(array, start, middle, end);
    }
}



// quick sort

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int findPivotIndex(vector<int>& array, int start, int end) {
    int i = start;
    int j = end;
    int pivotElement = array[start];

    while(i <= j) {
        while(i <= j && pivotElement <= array[i]) i++;
        while(i <= j && pivotElement > array[j]) j--;

        if(i < j) {
            swap(array[i], array[j]);
        }
    }
    swap(array[j], array[start]);
    return j;
}

void quickSort(vector<int> &array, int start, int end) {
    if(start < end) {
        int pivotIndex = findPivotIndex(array, start, end);
        quickSort(array, start, pivotIndex-1);
        quickSort(array, pivotIndex+1, end);
    }
}




int main()
{
    vector<int> array = {3,2,7,5,9,11,3,46,12,22,23,56,12,10,25,14,18,10,26};
    // mergeSort(array, 0, array.size() -1);
    quickSort(array, 0, array.size()-1);
    for(int i : array) {
        cout << i << " ";
    }
    return 0;
}