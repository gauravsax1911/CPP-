
//COMPLEXITY - SIZE OF QUEUE CAN GO UPTO MAXIMUM NUMBER OF EDGES

#include <bits/stdc++.h>
using namespace std;
class edge
{
public:
    int v, w;

    edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

void addedge(vector<vector<edge>> &graph, int u, int v, int w)
{
    graph[u].push_back(edge(v, w));
    graph[v].push_back(edge(u, w));
}

void bfs_graph(vector<vector<edge>> &graph, int src)
{
    int n = graph.size();
    queue<int> que;
    vector<bool> vis(n, false);
    que.push(src);
    int level = 0;
    while (que.size() != 0)
    {
        int size = que.size();
        cout<<"LEVEL"<<" "<<level<<"-->";
        while (size-- > 0)
        {
            int idx = que.front();
            que.pop();
            if(vis[idx])
            {continue;} 
            vis[idx] = true;
            for (edge e : graph[idx])
            {
                if (!vis[e.v])
                {
                    que.push(e.v);
                    cout<<e.v;
                }  
            }
        }
        level++;
        cout<<endl;
    }
}


void bfs_graph_withoutcycle(vector<vector<edge>> &graph, int src)
{
    int n = graph.size();
    queue<int> que;
    vector<bool> vis(n, false);
    que.push(src);
    vis[src] = true;
    int level = 0;
    while (que.size() != 0)
    {
        int size = que.size();
        cout<<"LEVEL"<<" "<<level<<"-->";
        while (size-- > 0)
        {
            int idx = que.front();
            que.pop();
            for (edge e : graph[idx])
            {
                if (!vis[e.v])
                {
                    que.push(e.v);
                    vis[e.v] = true;
                    cout<<e.v;
                }  
            }
        }
        level++;
        cout<<endl;
    }
}




int main()
{
    int v = 9;

    vector<vector<edge>> graph(v, vector<edge>());

    addedge(graph, 0, 3, 30);
    addedge(graph, 0, 1, 10);
    addedge(graph, 1, 2, 10);
    addedge(graph, 2, 3, 20);
    addedge(graph, 2, 7, 10);
    addedge(graph, 8, 7, 20);
    addedge(graph, 2, 8, 30);
    addedge(graph, 3, 4, 40);
    addedge(graph, 4, 5, 50);
    addedge(graph, 4, 6, 70);
    addedge(graph, 6, 5, 60);

    bfs_graph(graph,0);
    

    return 0;
}