#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;


class Graph {
    unordered_map<int, list<int>> adj;

    // direction == 0 --> undirected
    // direction == 1 --> directed fron node 1 -> node 2
    public:

    void addNode(int node) {
        adj[node] = {};
    }

    void addEdge(int node1, int node2, bool direction) {
        adj[node1].push_back(node2);
        if(!direction) {
            adj[node2].push_back(node1);
        }
    }

    void printGraph() {
        for(auto i : adj) {
            cout << i.first << ": ";
            for(auto j : i.second) {
                cout << j << " ";
            }
            cout << '\n';
        }
    }

};

int main()
{
    Graph g;
    int edges;

    cout << "Enter the number of edges: ";
    cin >> edges;

    int n1, n2;
    for(int i = 0; i < edges; ++i) {
        cin >> n1 >> n2;
        g.addEdge(n1, n2, false);
    }
    g.printGraph();

    return 0;
}