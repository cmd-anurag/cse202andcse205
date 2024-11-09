#include<iostream>
#include<vector>
#include<utility>
#include<iomanip>
#include<climits>

using namespace std;

class MyHeap {
    vector<int> array;

    public:
        void push(int data) {
            array.push_back(data);
            int elementIndex = array.size() -1;

            while(elementIndex > 0) {
                int parentIndex = (elementIndex - 1) / 2;
                
                if(array[parentIndex] < array[elementIndex]) {
                    swap(array[parentIndex], array[elementIndex]);
                }
                else {
                    break;
                }
                elementIndex = parentIndex;
            }
        }

        void pop() {
            if(array.empty()) {
                cout << "Heap is empty\n";
                return;
            }

            array[0] = array.back();
            array.pop_back();

            int elementIndex = 0;

            while(elementIndex < array.size()) {

                int leftChildIndex = 2*elementIndex + 1;
                int rightChildIndex = 2*elementIndex + 2;

                int maxIndex = elementIndex;

                if(leftChildIndex < array.size() && array[leftChildIndex] > array[maxIndex]) {
                    maxIndex = leftChildIndex;
                }

                if(rightChildIndex < array.size() && array[rightChildIndex] > array[maxIndex]) {
                    maxIndex = rightChildIndex;
                }
                if(elementIndex == maxIndex) {
                    break;
                }
                else {
                    swap(array[elementIndex], array[maxIndex]);
                    elementIndex = maxIndex;
                }
            }
        }

        int top() {
            if(array.empty()) {
                cout << "Heap is Empty\n";
                return -1;
            }
            return array[0];
        }

        bool empty() {
            return array.empty();
        }

};

// You are using GCC

class MinHeap {
    vector<int> heap;
    
    void minHeapify(vector<int> &array, int i) {
        
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        
        if(left < array.size() && array[left] < array[smallest]) {
            smallest = left;
        }
        if(right < array.size() && array[right] < array[smallest]) {
            smallest = right;
        }
        
        if(smallest != i) {
            swap(array[smallest], array[i]);
            minHeapify(array, smallest);
        }
    }
    
    public:
    MinHeap() {};
    
    MinHeap(vector<int> array) {
        int n = array.size();
        for(int i = n/2-1; i >= 0; --i) {
            minHeapify(array, i);
        }
        heap = array;
    }
    
    void push(int value) {
        heap.push_back(value);
        int elementIndex = heap.size() - 1;
        
        while(elementIndex > 0) {
            int parentIndex = (elementIndex - 1)/2;
            if(heap[parentIndex] > heap[elementIndex]) {
                swap(heap[parentIndex], heap[elementIndex]);
                elementIndex = parentIndex;
            }
            else {
                break;
            }
        }
    }
    
    void pop() {
        if(heap.empty()) {
            return;
        }    
        heap[0] = heap.back();
        heap.pop_back();
        
        int i = 0;
        
        while(i < heap.size()) {
            int smallest = i;
            int left = 2*i + 1;
            int right = 2*i + 2;
            
            if(left < heap.size() && heap[left] < heap[smallest]) {
                smallest = left;
            }
            
            if(right < heap.size() && heap[right] < heap[smallest]) {
                smallest = right;
            }
            if(i == smallest) {
                break;
            }
            swap(heap[smallest], heap[i]);
            i = smallest;
        }
        
    }
    void printHeap() {
        for(int i : heap) {
            cout << i << " ";
        }
        cout << '\n';
    }
    int top() {
        return heap[0];
    }
    int findMax() {
       int maxval = INT_MIN;
       for(int i : heap) {
           maxval = max(maxval, i);
       }
       return maxval;
    }
    int sumNodes() {
        int sum = 0;
        for(int i : heap) {
            sum += i;
        }
        return sum;
    }
    int size() {
        return heap.size();
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> array(n);
    for(int i = 0; i < n; ++i) {
        cin >> array[i];
    }
    MinHeap h;
    for(int i : array) {
        h.push(i);
    }
    cout << "Min Heap: ";
    h.printHeap();
    cout << "Root Node: " << h.top() << '\n';
    h.pop();
    cout << "Maximum Value: " << h.findMax() << '\n';
    int sum = h.sumNodes();
    cout << "Sum of Nodes: " << sum << '\n';
    cout << fixed << setprecision(2) << "Average of Nodes: " << ((double)sum / (double)h.size());
    
    
}



// int main()
// {
//     MyHeap maxHeap;
//     maxHeap.push(21);
//     maxHeap.push(33);
//     maxHeap.push(3);
//     maxHeap.push(34);
//     maxHeap.push(8);
//     maxHeap.push(3);
//     maxHeap.push(29);
//     cout << maxHeap.top() << "\n";
//     maxHeap.pop();
//     cout << maxHeap.top() << "\n";
//     maxHeap.pop();
//     cout << maxHeap.top() << "\n";
//     maxHeap.pop();
//     cout << maxHeap.top() << "\n";
//     maxHeap.pop();
//     cout << maxHeap.top() << "\n";
//     maxHeap.pop();
//     cout << maxHeap.top() << "\n";
//     maxHeap.pop();
//     cout << maxHeap.top() << "\n";


//     // empty heap
//     maxHeap.pop();
//     cout << maxHeap.top() << "\n";
//     return 0;
// }