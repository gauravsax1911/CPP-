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
static std::vector<bool> vis;
static std::vector<bool> APoints;
static std::vector<int> low;
static std::vector<int> disc;
static std::vector<int> ap;
static int tym = 0;
static int rootcalls = 0;

void addedge(vector<vector<edge>> &graph, int u, int v, int w)
{
    graph[u].push_back(edge(v, w));
    graph[v].push_back(edge(u, w));
}

void dfs_articulation(vector<vector<edge>> &graph, int src, int par)
{
    low[src] = disc[src] = tym++;
    vis[src] = true;

    for (edge e : graph[src])
    {
        if (!vis[e.v])
        {
            if (par == -1)
            {
                rootcalls++;
            }

            dfs_articulation(graph, e.v, src);
            if (disc[src] <= low[e.v])
            {
                ap[src]++;
                APoints[src] = false;
            }
            if(disc[src] < low[e.v])
            {
                cout<<"Articulation Bridge"<<endl;
            }
            low[src] = min(low[src], low[e.v]);
        }

        else if (e.v != par)
        {
            low[src] = min(low[src], disc[e.v]);
        }
    }
}

void ArticulationPoint(vector<vector<edge>> &graph, int n)
{
    vis.resize(n, false);
    low.resize(n);
    disc.resize(n);
    ap.resize(n);
    APoints.resize(n);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            ap[i] = -1;
            dfs_articulation(graph, i, -1);
            if (rootcalls == 1)
            {
                APoints[i] = false;
            }
        }
    }
}

int main()
{
}