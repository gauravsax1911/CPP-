#include <bits/stdc++.h>
using namespace std;

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

// 1*  BFS

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
        cout << "LEVEL"
             << " " << level << "-->";
        while (size-- > 0)
        {
            int idx = que.front();
            que.pop();
            if (vis[idx])
            {
                continue;
            }
            vis[idx] = true;
            for (edge e : graph[idx])
            {
                if (!vis[e.v])
                {
                    que.push(e.v);
                    cout << e.v;
                }
            }
        }
        level++;
        cout << endl;
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
        cout << "LEVEL"
             << " " << level << "-->";
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
                    cout << e.v;
                }
            }
        }
        level++;
        cout << endl;
    }
}
void dfs(vector<vector<edge>> &graph, int src, int des, vector<bool> &vis)
{
    if (src == des)
    {
        return;
    }

    vis[src] = true;
    for (edge e : graph[src])
    {
        if (!vis[e.v])
        {
            dfs(graph, e.v, des, vis);
        }
    }

    vis[src] = false;
}
// 2* Dijikstra

// Priority queue instead of queue
// It is single source algo, gives the shortest path from source to parination
// In it the sum from source to parination is minimum whereas in MST the sum of edges is minimum. So it's possible the overall sum of
//edges in dijikstra is greater than MST but is ensured that to parination the path is shortest.

// For dijikstra we need, (source,parination,wt,psf)

class pair_
{
public:
    int src;
    int par;
    int wt;
    int wsf;
    // dijisktra
    pair_(int src, int par, int wt, int wsf)
    {
        this->src = src;
        this->par = par;
        this->wt = wt;
        this->wsf = wsf;
    }
    //prims
    pair_(int src, int par, int wt)
    {
        pair_(src, par, wt, 0);
    }
    // dijisktra better
    pair_(int src, int wsf)
    {
        pair_(src, -1, 0, wsf);
    }
};

struct comp
{
    bool operator()(pair_ &a, pair_ &b)
    {
        return a.wsf > b.wsf;
    }
};

void display(vector<vector<edge>> &mygraph)
{
    for (int i = 0; i < mygraph.size(); i++)
    {
        cout << i << "--------->";
        for (edge e : mygraph[i])
        {
            cout << e.v << " ";
        }
        cout << endl;
    }
}

void dijikstra(vector<vector<edge>> &graph, int src, int n)
{
    vector<bool> vis(n, false);
    vector<vector<edge>> mygraph(n, std::vector<edge>());

    priority_queue<pair_, vector<pair_>, comp> pq;
    pq.push(pair_(0, -1, 0, 0));

    while (pq.size() != 0)
    {
        pair_ p = pq.top();
        pq.pop();

        if (vis[p.src])
        {
            continue;
        }
        if (p.par != -1)
        {
            addedge(mygraph, p.par, p.src, p.wsf);
        }
        vis[p.src] = true;
        for (edge e : graph[p.src])
        {
            if (!vis[e.v])
            {
                pq.push(pair_(e.v, p.src, e.w, p.wsf + e.w));
            }
        }
    }

    display(mygraph);
}

struct comp1
{
    bool operator()(pair_ &a, pair_ &b)
    {
        return a.wt > b.wt;
    }
};

void prims(vector<vector<edge>> &graph, int src, int n)
{
    vector<bool> vis(n, false);
    vector<vector<edge>> mygraph(n, std::vector<edge>());

    priority_queue<pair_, vector<pair_>, comp1> pq;
    pq.push(pair_(0, -1, 0, 0));

    while (pq.size() != 0)
    {
        pair_ p = pq.top();
        pq.pop();

        if (vis[p.src])
        {
            continue;
        }
        if (p.par != -1)
        {
            addedge(mygraph, p.par, p.src, p.wsf);
        }
        vis[p.src] = true;
        for (edge e : graph[p.src])
        {
            if (!vis[e.v])
            {
                pq.push(pair_(e.v, p.src, e.w, p.wsf + e.w));
            }
        }
    }

    display(mygraph);
}

void dijikstra_btr(vector<vector<edge>> &graph, int v, int src)
{
    vector<vector<edge>> mygraph(v, std::vector<edge>());
    vector<bool> vis(v, false);
    vector<int> dis(v, (int)1e9);
    vector<int> par(v, -1);
    priority_queue<pair_, vector<pair_>, comp> pq;
    pq.push(pair_(src, 0));
    dis[src] = 0;
    while (pq.size() != 0)
    {
        pair_ p = pq.top();
        pq.pop();
        if (vis[p.src])
        {
            continue;
        }

        if (par[p.src] != -1)
        {
            addedge(mygraph, par[p.src], p.src, p.wsf);
        }

        for (edge e : graph[p.src])
        {
            if (!vis[e.v] && e.w + p.wsf < dis[e.v])
            {
                pq.push(pair_(e.v, e.w + p.wsf));
                dis[e.v] = e.w + p.wsf;
                par[e.v] = p.src;
            }
        }
    }
    display(mygraph);
}

int main()
{
    int n = 9;
    vector<vector<edge>> graph(n, std::vector<edge>());
    addedge(graph, 0, 1, 4);
    addedge(graph, 0, 7, 8);
    addedge(graph, 1, 7, 11);
    addedge(graph, 1, 2, 8);
    addedge(graph, 7, 8, 7);
    addedge(graph, 7, 6, 1);
    addedge(graph, 6, 8, 6);
    addedge(graph, 6, 5, 2);
    addedge(graph, 2, 5, 4);
    addedge(graph, 5, 3, 14);
    addedge(graph, 5, 4, 10);
    addedge(graph, 3, 4, 9);
    addedge(graph, 2, 3, 7);
    addedge(graph, 2, 8, 2);
    dijikstra_btr(graph, 0, n);
    
}
