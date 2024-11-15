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


// neocolab shortest path bfs
// You are using GCC
#include<unordered_map>
#include<vector>
#include<queue>


void add_edge(int adj[][100], int src, int dest)
{
    //Type your code
    adj[src][dest] = 1;
    adj[dest][src] = 1;
}

bool BFS(int adj[][100], int src, int dest, int v, int pred[], int dist[])
{
    //Type your code
    queue<int> q;
    unordered_map<int, bool> visited;
    
    for(int i = 0; i < v; ++i) {
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
    
    q.push(src);
    dist[src] = 0;
    visited[src] = true;
    
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        
        for(int i = 0; i < v; ++i) {
            if(adj[front][i] && !visited[i]) {
                q.push(i);
                dist[i] = dist[front] + 1;
                pred[i] = front;
                visited[i] = true;
                
                if(i == dest) {
                    return true;
                }
            }
        }
    }
    return false;
}

void printShortestDistance(int adj[][100], int s, int dest, int v, int pred[], int dist[])
{
    //Type your code
    vector<int> path;
    int crawl = dest;
    
    path.push_back(crawl);
    
    while(pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }
    
    cout << "Shortest path length is: " << dist[dest] << '\n';
    cout << "Path is: ";
    for(int i = path.size()-1; i >= 0; --i) {
        cout << path[i] << " ";
    }
}