#include<bits/stdc++.h>
using namespace std;

void add_edge(int adj[][100], int src, int dest)
{
    //Type your code
    adj[src][dest] = 1;
    adj[dest][src] = 1;
}

bool BFS(int adj[][100], int src, int dest, int v, int pred[], int dist[])
{
    //Type your code
    unordered_map<int, bool> visited;
    queue<int> q;

    q.push(src);
    dist[src] = 0;
    pred[src] = -1;

    while(!q.empty()) {
        int front = q.front();
        q.pop();

        for(int i = 0; i < v; ++i) {
            if(adj[front][i] && visited.find(i) == visited.end()) {
                dist[i] = dist[front] + 1;
                pred[i] = front;
                visited[i] = true;
                q.push(i);

                if(i == dest) return true;
            }
        }
    }
}

void printShortestDistance(int adj[][100], int s, int dest, int v, int pred[], int dist[])
{
    //Type your code
    vector<int> path;
    path.push_back(dest);
    int crawl = dest;

    while(pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }

    for(vector<int>::iterator it = path.end(); it != path.begin(); --it) {
        cout << *it << " ";
    }
}