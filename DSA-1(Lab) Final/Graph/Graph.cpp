
//Class Code
#include<iostream>
#include<queue>
#include<stack>
#define SIZE 100
using namespace std;

class Graph
{
    bool directed;
    int n_vertices;
    int adj[SIZE][SIZE];
    bool visited[SIZE];

    public:
    Graph(int v, bool dir)
    { n_vertices=v;
      directed=dir;

      for(int i=0; i<n_vertices; i++)
      {
          for(int j=0; j<n_vertices; j++)
          {
              adj[i][j]=0;
          }
      }


    }

    void init_visited()
    {
        for(int i=0; i<n_vertices;i++)
        {
            visited[i]=false;
        }

    }



    void addEdge(int u, int v)
    {
        adj[u][v]=1;
        if(!directed)
        {
            adj[v][u]=1;
        }

    }

    void printGraph()
    {
        for(int i=0; i<n_vertices; i++)
        {
            for(int j=0; j<n_vertices; j++)
            {
                cout<<adj[i][j]<<" ";
            }

            cout<<endl;
        }
    }


    void BFS(int start)
    {
        queue<int> q;
        q.push(start);
        visited[start]=true;
        cout<<"BFS Traversal: ";


        while(!q.empty())
        {

        int u=q.front();
        q.pop();
        cout<<u<<" ";

        for(int v=0; v<n_vertices; v++)
        {
            if(adj[u][v]==1 && !visited[v])
            {
                q.push(v);
                visited[v]=true;
            }
        }

        }

        cout<<endl;



    }


    void DFS(int start)
    {
        stack<int> s;
        s.push(start);
        visited[start]=true;
        cout<<"DFS Traversal: ";


        while(!s.empty())
        {

        int u=s.top();
        s.pop();
        cout<<u<<" ";

        for(int v=0; v<n_vertices; v++)
        {
            if(adj[u][v]==1 && !visited[v])
            {
                s.push(v);
                visited[v]=true;
            }
        }

        }

        cout<<endl;
    }

    void DFS_recursive(int start)
    {
        int u=start;
        visited[u]=true;

        cout<<u<<" ";

        for(int v=0; v<n_vertices; v++)
        {
            if(adj[u][v]==1 && !visited[v])
            {
                DFS_recursive(v);
            }
        }
    }
};


int main()
{
    Graph g(7,false);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(3,1);
    g.addEdge(4,1);
    g.addEdge(2,5);
    g.addEdge(2,6);

    g.printGraph();

    g.init_visited();
    g.BFS(0);

    g.init_visited();
    g.DFS(0);

    cout<<"DFS Recursive: ";
    g.init_visited();
    g.DFS_recursive(0);



}
