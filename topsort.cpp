#include <bits/stdc++.h> 
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int, list<int>> adj;

    for(int i = 0; i < e; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    vector<int> indegree(v, 0);
    for(auto i : adj) {
        for(auto j : i.second) {
            indegree[j]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < v; ++i) {
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> result;

    while(!q.empty()) {
        int front = q.front();
        q.pop();
        result.push_back(front);
        for(auto n : adj[front]) {
            indegree[n]--;
            if(indegree[n] == 0) {
                q.push(n);
            }
        }
    }

    return result;
}

int main() {

}