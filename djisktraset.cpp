#include <bits/stdc++.h> 
using namespace std;


vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int, list<pair<int, int>>> adj;

    for(int i = 0; i < edges; ++i) {
        int u = vec[i][0];
        int v = vec[i][1];

        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> distance(vertices, INT_MAX);

    set<pair<int, int>> st;

    distance[source] = 0;

    st.insert(make_pair(0, source));

    while(!st.empty()) {
        auto top = *st.begin();
        st.erase(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        for(auto neighbor : adj[topNode]) {
            if(nodeDistance + neighbor.second < distance[neighbor.first]) {
                auto record = st.find(make_pair(distance[neighbor.first], neighbor.first));
                if(record != st.end()) {
                    st.erase(record);
                }
                distance[neighbor.first] = nodeDistance+neighbor.second;
                st.insert(make_pair(distance[neighbor.first], neighbor.first));
            }
        }
    }

    return distance;

    
}
