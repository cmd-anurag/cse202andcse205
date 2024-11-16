#include<bits/stdc++.h>
using namespace std;



class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        unordered_map<int, vector<int>> adjlist;
        
        for(int i = 0; i < adj.size(); ++i) {
            
            for(int j = 0; j < adj[i].size(); ++j) {
                adjlist[i].push_back(adj[i][j]);
            }
        }
        
        unordered_map<int, bool> visited;
        stack<int> st;
        
        vector<int> result;
        
        st.push(0);
        
        while(!st.empty()) {
            int top = st.top();
            st.pop();
            
            if(!visited[top]) {
                result.push_back(top);
            }
            
            
            visited[top] = true;
            
            for(int i = adjlist[top].size()-1; i >= 0; --i) {
                if(!visited[adjlist[top].at(i)]) {
                    st.push(adjlist[top].at(i));
                }
            }
            
        }
        
        return result;
    }
};

// Disconnected Graph

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int, vector<int>> adjlist;

    for(int i = 0; i < edges.size(); ++i) {

        for(int j = 0; j < edges[i].size(); ++j) {
            adjlist[i].push_back(edges[i][j]);
        }
    }

    unordered_map<int, bool> visited;
    vector<vector<int>> result;

    stack<int> st;

    for(int i = 0; i < V; ++i) {
        if(visited.find(i) == visited.end() || visited[i] == false) {
            vector<int> component;
            // clear the stack or make it local
            st.push(i);
            while(!st.empty()) {
                int top = st.top();
                st.pop();
                if(!visited[top]) {
                    component.push_back(top);
                }
                visited[top] = true;
                for(int i = adjlist[top].size()-1; i >= 0; --i) {
                    if(!visited[adjlist[top][i]]) {
                        st.push(adjlist[top][i]);
                    }
                }
            }

            result.push_back(component);
        }
    }

}