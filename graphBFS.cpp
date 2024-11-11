#include<bits/stdc++.h>
using namespace std;


vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    vector<int> result;
    queue<int> q;
    unordered_map<int, bool> visited;
    q.push(0);
    visited[0] = true;

    while(!q.empty()) {
        int current = q.front();
        q.pop();
        result.push_back(current);

        for(int i : adj[current]) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    return result;
    

}