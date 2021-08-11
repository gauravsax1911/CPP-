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

// Complexity : 2E
// O(2E)

void display(vector<vector<edge>> &graph, int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << i << "--->";
        vector<edge> v1 = graph[i]; // for(edge e : graph[i])
                                    // { cout <<}
        for (int j = 0; j < v1.size(); j++)
        {
            cout << "(" << v1[j].v << "," << v1[j].w << ")"
                 << " ";
        }
        cout << endl;
    }
}

void removeedge(vector<vector<edge>> &graph, int u, int v)
{

    vector<edge> v1 = graph[u];
    vector<edge> v2 = graph[v];
    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i].v == v)
        {
            graph[u].erase(graph[u].begin() + i);
        }
    }

    for (int i = 0; i < v2.size(); i++)
    {
        if (v2[i].v == u)
        {
            graph[v].erase(graph[v].begin() + i);
        }
    }
}

int findedge(vector<vector<edge>> &graph, int u, int v)
{

    vector<edge> v1 = graph[u];
    int ans = -1;
    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i].v == v)
        {
            ans = i;
            break;
        }
    }

    return ans;
}

void removevtx(vector<vector<edge>> &graph, int u)
{
    vector<edge> v1 = graph[u];
    for (int i = v1.size() - 1; i >= 0; i--)
    {
        removeedge(graph, u, v1[i].v);
    }

    // graph.erase(graph.begin()+u);
}



bool haspath(vector<vector<edge>> &graph, int source, int destination , vector<bool> vis)
{
    if(source == destination)
    { return true;}

   bool res = false;
    vis[source] = true;
    for(edge e : graph[source])
    {
        if(!vis[e.v])
        { res = res || haspath(graph,e.v,destination,vis);}

    }

    return res;
}

int hasallpath(vector<vector<edge>> &graph, int src,int des,string psf,vector<bool> vis)
{
    if(src == des)
    {
        cout<<(psf) + to_string(des)<<endl;
        return 1;
    }

    int count = 0;
    vis[src] = true;

    for(edge e : graph[src])
    {
        if(!vis[e.v])
        {
            count += hasallpath(graph,e.v,des,psf + to_string(src) , vis);

        }
    }
    vis[src] = false;
    return count;

}

int main()
{
    int v = 9;

    vector<vector<edge>> graph(v, vector<edge>());

    addedge(graph, 0, 3, 10);
    addedge(graph, 0, 1, 10);
    addedge(graph, 1, 2, 10);
    addedge(graph, 2, 3, 40);
    addedge(graph, 2, 7, 2);
    addedge(graph, 8, 7, 3);
    addedge(graph, 2, 8, 4);
    addedge(graph, 3, 4, 2);
    addedge(graph, 4, 5, 2);
    addedge(graph, 4, 6, 8);
    addedge(graph, 6, 5, 3);

    // display(graph, v);
    // cout << "===========================" << endl;
    // //    removeedge(graph,2,3);
    //    removeedge(graph,0,3);
    //    display(graph,v);

    //    cout<<"======================"<<endl;
    //    cout<<findedge(graph,2,3)<<endl;
    //    cout<<findedge(graph,4,6)<<endl;
    // removevtx(graph, 2);
    // display(graph, v);

    vector<bool> vis(v,false);
    // removeedge(graph,0,3);
    removeedge(graph,0,1);
    cout<<haspath(graph,0,6,vis)<<endl;
    cout<<hasallpath(graph,0,6,"",vis)<<endl;
    return 0;
}
