#include<iostream>
#include<vector>
#include<utility>

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



int main()
{
    MyHeap maxHeap;
    maxHeap.push(21);
    maxHeap.push(33);
    maxHeap.push(3);
    maxHeap.push(34);
    maxHeap.push(8);
    maxHeap.push(3);
    maxHeap.push(29);
    cout << maxHeap.top() << "\n";
    maxHeap.pop();
    cout << maxHeap.top() << "\n";
    maxHeap.pop();
    cout << maxHeap.top() << "\n";
    maxHeap.pop();
    cout << maxHeap.top() << "\n";
    maxHeap.pop();
    cout << maxHeap.top() << "\n";
    maxHeap.pop();
    cout << maxHeap.top() << "\n";
    maxHeap.pop();
    cout << maxHeap.top() << "\n";


    // empty heap
    maxHeap.pop();
    cout << maxHeap.top() << "\n";
    return 0;
}