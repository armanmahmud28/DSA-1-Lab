//undirected & unweighted

#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int> >& graph, int S,
         vector<int>& par, vector<int>& dist)
{
    
    queue<int> q;
    dist[S] = 0;
    q.push(S);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbour : graph[node]) {
            // Check if the neighbouring node is not visited
            if (dist[neighbour] == 1e9) {
                // Mark the current node as the parent of
                // the neighbouring node
                par[neighbour] = node;
                // Mark the distance of the neighbouring
                // node as distance of the current node + 1
                dist[neighbour] = dist[node] + 1;
                // Insert the neighbouring node to the queue
                q.push(neighbour);
            }
        }
    }
}

// Function to print the shortest distance between source
void printShortestDistance(vector<vector<int> >& graph,
                           int S, int D, int V)
{
    // par[] array stores the parent of nodes
    vector<int> par(V, -1);

    // dist[] array stores distance of nodes from S
    vector<int> dist(V, 1e9);

    // function call to find the distance of all nodes and
    // their parent nodes
    bfs(graph, S, par, dist);
    
    if (dist[D] == 1000000000) {
    cout << "No path exists between source and destination.";
    return;
}


    // vector path stores the shortest path
    vector<int> path;
    int currentNode = D;
    path.push_back(D);
    while (par[currentNode] != -1) {
        path.push_back(par[currentNode]);
        currentNode = par[currentNode];
    }

    // printing path from source to destination
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
}

// Driver program to test above functions
int main()
{
    // no. of vertices
    int V = 8, E = 10;
    // Source and Destination vertex
    int S = 2, D = 6;
    // edge list
    vector<vector<int> > edges
        = { { 0, 1 }, { 1, 2 }, { 0, 3 }, { 3, 4 },
            { 4, 7 }, { 3, 7 }, { 6, 7 }, { 4, 5 },
            { 4, 6 }, { 5, 6 } };

    // vector to store the graph as adjacency list
    vector<vector<int> > graph(V);
    for (int i=0;i<edges.size();i++) {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    printShortestDistance(graph, S, D, V);
    return 0;
}