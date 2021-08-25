#include <bits/stdc++.h>
using namespace std;
class edge
{
public:
    int v;
    int w;
    edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};
void addedge(vector<vector<edge>> &graph, int u, int v, int w)
{
    graph[u].push_back(edge(v, w));
}

class primspair{
    public:
    int vtx=0;
    int par=0;
    int w =0;
    primspair(int vtx,int par,int w)
    {
        this->vtx = vtx;
        this->par = par;
        this->w = w;
    }
};

void prims_algoform_01(vector<vector<edge>> &graph, int n,int src)
{
    vector<bool> vis(n,0);
    priority_queue<primspair> que;
    que.push(primspair(src,-1,0));
    while(que.size() != 0)
    {
        primspair p = que.top();
        que.pop();
        if(!vis[p.vtx])
        {continue;}
   }


}
int main()
{
    int n = 9;
    vector<vector<edge>> graph(n);
    addedge(graph, 0, 1, 4);
    addedge(graph, 0, 7, 8);

    addedge(graph, 7, 1, 11);
    addedge(graph, 2, 1, 8);

    addedge(graph, 7, 8, 1);
    addedge(graph, 6, 7, 7);

    addedge(graph, 2, 8, 2);
    addedge(graph, 2, 3, 7);
    addedge(graph, 2, 5, 4);

    addedge(graph, 5, 6, 2);
    addedge(graph, 5, 3, 14);
    addedge(graph, 5, 4, 10);

    addedge(graph, 3, 4, 9);
}