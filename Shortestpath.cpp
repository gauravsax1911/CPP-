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

class pair_
{
public:
    int shortpath;
    string psf = "";

    pair_(int shortpath, string psf)
    {
        this->shortpath = shortpath;
        this->psf = psf;
    }
};

pair_ shortpath(vector<vector<edge>> &graph, int src, int des, vector<bool> vis)
{
    if (src == des)
    {
        pair_ base(0, to_string(src));
        return base;
    }

    vis[src] = true;
    pair_ myans((int)1e9, "");

    for (edge e : graph[src])
    {
        if (!vis[e.v])
        {
            pair_ recans = shortpath(graph, e.v, des, vis);
            if (recans.shortpath != (int)1e9 && recans.shortpath + e.w < myans.shortpath)
            {
                myans.shortpath = recans.shortpath + e.w;
                myans.psf = to_string(src) + recans.psf;
            }
        }
    }
    vis[src] = false;
    return myans; 
}

int main()
{

    int v = 7;
    vector<vector<edge>> graph(v, vector<edge>());
    addedge(graph, 0, 1, 1);
    addedge(graph, 2, 1, 2);
    addedge(graph, 2, 3, 3);
    addedge(graph, 0, 3, 1);
    addedge(graph, 3, 4, 3);
    addedge(graph, 4, 5, 1);
    addedge(graph, 5, 6, 7);
    addedge(graph, 4, 6, 4);

    vector<bool> vis(v, false);
    pair_ ans = shortpath(graph, 0, 6, vis);
    cout << ans.shortpath << endl;
    cout<<ans.psf<<endl;
}
