#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    void segregateElements(vector<int>& arr) {
        // Your code goes here
        vector<int> positives;
        vector<int> negatives;
        
        for(int i : arr)
        {
            if(i < 0) {
                negatives.push_back(i);
            }
            else {
                positives.push_back(i);
            }
        }
        
        int index = 0;
        for(; index < positives.size(); ++index) {
            arr[index] = positives[index];
        }
        
        for(int i = 0; i < negatives.size(); ++i) {
            arr[index] = negatives[i];
            ++index;
        }
        
    }
};