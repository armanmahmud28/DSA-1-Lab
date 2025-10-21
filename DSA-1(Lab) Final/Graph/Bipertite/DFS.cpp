#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> constructadj(int V, vector<vector<int>> &edges){
    
    vector<vector<int>> adj(V);
    for(int i = 0; i < edges.size(); i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    return adj;
}

// Helper function for DFS to check bipartite graph
bool dfs(int u, int color, vector<int> &colors,
                           vector<vector<int>> &adj) {

    // Assign color to the current u
    colors[u] = color; 

    // Iterate through all adjacent vertices
    for(auto &v : adj[u]) {
        if(colors[v] == -1) {

            // Assign alternate color to the adjacent u
            if(!dfs(v, 1 - color, colors, adj))
                return false;
        }
        else if(colors[v] == color) {
          
            // If the adjacent u has the same color,
            // it's not bipartite
            return false;
        }
    }
    return true;
}

// Function to check if the graph is Bipartite using DFS
bool isBipartite(int V, vector<vector<int>> &edges) {

    // Initialize all vertices as uncolored
    vector<int> colors(V, -1); 
    
    // create adjacency list
    vector<vector<int>> adj = constructadj(V,edges);

    // Check each component of the graph
    for(int i = 0; i < V; i++) {

        // If the vertex is uncolored
        if(colors[i] == -1) { 

            // If DFS fails, the graph is not bipartite
            if(!dfs(i, 0, colors, adj))
                return false; 
        }
    }

    // All vertices can be colored bipartitely
    return true;
}

int main() {
    
    int V = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    if(isBipartite(V, edges))
        cout << "true";
    else
        cout << "false";
    
    return 0;
}
