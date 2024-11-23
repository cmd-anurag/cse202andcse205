
#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        unordered_map<int, int> freq;
        for(int i : arr) {
            freq[i]++;
        }
        unordered_map<int, int>::iterator it = freq.begin();
        
        vector<int> result;
        
        
        while(it != freq.end()) {
            if(it->second > 1) {
                result.push_back(it->first);        
            }
            ++it;
        }
        sort(result.begin(), result.end());
        return result;
    }
};