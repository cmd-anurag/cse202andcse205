#include <iostream>
using namespace std;

#define MAXN 100
int INF = 1e7;

int dis[MAXN][MAXN];
int Next[MAXN][MAXN];
// You are using GCC
void initialise(int n, int arr[MAXN][MAXN]) {
    //Type your code here
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            dis[i][j] = arr[i][j];
            Next[i][j] = -1;
        } 
    }
}

void floydWarshall(int V) {

    //Type your code here
    for(int k = 0; k < V; ++k) {
        for(int i = 0; i < V; ++i) {
            for(int j = 0; j<V; ++j){
                if(dis[i][k] == INF || dis[k][j] == INF) {
                    continue;
                    
                }
                int oldDistance = dis[i][j];
                int newDistance = dis[i][k]+dis[k][j];
                if(newDistance < oldDistance) {
                    dis[i][j] = newDistance;
                    Next[i][j] = k;
                }
                else {
                    Next[i][j] = j;
                }
            }
        }
    }
    
}

void printPath(int path[], int n) {
    //Type your code here
    for(int i = 0; i < n; ++i) {
        cout << path[i] << " ";
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