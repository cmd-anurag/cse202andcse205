#include <iostream>
using namespace std;

#define MAXN 100
int INF = 1e7;

int dis[MAXN][MAXN];
int Next[MAXN][MAXN];

void initialise(int V, int graph[MAXN][MAXN]) {
    //Type your code here
    for(int i = 0; i < V; ++i) {
        for(int j = 0; j < V; ++j) {
            
            
            if(graph[i][j] != 0) {
                dis[i][j] = graph[i][j];
                Next[i][j] = j;
            }
            else {
                dis[i][j] = INF;
                Next[i][j] = -1;
            }
        }
    }
}

void floydWarshall(int V) {
    //Type your code here
    for(int k = 0; k < V; ++k) {
        for(int i = 0; i < V; ++i) {
            for(int j = 0; j < V; ++j) {
                if(dis[i][k] == INF || dis[k][j] == INF) {
                    continue;
                }
                
                if(dis[i][k]+dis[k][j] < dis[i][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    Next[i][j] = Next[i][k];
                }
            }
        }
    }
    
}

void printPath(int path[], int n) {
    //Type your code here
    for(int i = 0; i < n; ++i) {
        
        cout << path[i] << " ";
        if(i != n-1) {
            cout << "->";
        }
    }
}

int main() {
    int V;
    cin >> V;

    int graph[MAXN][MAXN];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    initialise(V, graph);
    floydWarshall(V);

    int u, v;
    cin >> u;
    cin >> v;

    int path[MAXN];
    path[0] = u;
    int index = 1;
    while (u != v) {
        u = Next[u][v];
        path[index++] = u;
    }

    cout << "Shortest path from " << path[0] << " to " << path[index - 1] << ": ";
    printPath(path, index);

    return 0;
}