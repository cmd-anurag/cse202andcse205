#include<iostream>
#include<vector>


using namespace std;

void mergeArray(vector<int> &array, int start, int middle, int end) {
    vector<int> result(end - start + 1);

    int i = start;
    int j = middle+1;
    
    // index for merged result array
    int k = 0;

    while(i <= middle && j <= end) {
        if(array[i] < array[j]) {
            result[k] = array[i];
            ++k;
            ++i;
        }
        else if(array[i] > array[j]) {
           result[k] = array[j];
           ++k;
           ++j;
        }
        else {
            result[k] = array[i];
            ++k;
            ++i;
            result[k] = array[j];
            ++j;
        }
    }

    while(i <= middle) {
        result[k] = array[i];
        ++k;
        ++i;
    }

    while(j <= end) {
        result[k] = array[j];
        ++k;
        ++j;
    }

    // overwrite the orginal subarray with sorted subarray
    k = 0;
    while(start <= end) {
        array[start] = result[k];
        ++start;
        ++k;
    }
    
}


void MergeSort(vector<int> &array, int start, int end) {
    if(start < end) {
        int middle = (start+end)/2;
        MergeSort(array, start, middle);
        MergeSort(array, middle+1, end);
        mergeArray(array, start, middle, end);
    }
}


int main()
{
    vector<int> array = {5,1,3,7,2,12,11,4,9};
    MergeSort(array, 0, array.size()-1);
    for(int i : array) {
        cout << i << " ";
    }
    return 0;
}