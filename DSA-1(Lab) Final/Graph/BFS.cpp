#include <bits/stdc++.h>
using namespace std;

// BFS from given source s
vector<int> bfs(vector<vector<int>> &adj)
{
    int V = adj.size();
    int s = 0; 

    vector<int> res;
    queue<int> q;
    vector<bool> visited(V, false);

    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        res.push_back(curr);

        // Visit all unvisited adjacent vertices
        for (int x : adj[curr])
        {
            if (!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> adj = {{1, 2}, {0, 2, 3}, {0, 4}, {1, 4}, {2, 3}};
    vector<int> ans = bfs(adj);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}
