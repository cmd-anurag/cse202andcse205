#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int output = arr[n-1] - arr[0];
        
        int maxHeight;
        int minHeight;
        
        for(int i = 1; i < n; ++i) {
            if(arr[i] - k < 0) {
                continue;
            }
            
            maxHeight = max(arr[n-1]-k, arr[i-1]+k);
            minHeight = min(arr[0]+k, arr[i]-k);
            
            output = min(output, maxHeight - minHeight);
        }
        return output;
    }
};