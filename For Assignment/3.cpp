#include <bits/stdc++.h>
using namespace std;

void shortestPathBFS(int V, vector<pair<int,int>> &edges, int start) {
    vector<vector<int>> adj(V);
    for (auto e : edges) {
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }

    vector<int> d(V, INT_MAX);
    queue<int> q;
    d[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (d[v] == INT_MAX) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }

    cout << "Distance from " << start << ": ";
    for (int d : d) cout << d << " ";
    cout << endl;
}

int main() {
    int V = 5;
    vector<pair<int,int>> edges = {{0,1},{0,2},{1,3},{1,4},{2,4},{3,4}};
    int start = 0;
    shortestPathBFS(V, edges, start);
    return 0;
}
