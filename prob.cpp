
//LONGEST PATH IN TERMS OF WEIGHT

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

class pair_{
  public:
  int heavypath;
  string psf = "";

 
  pair_(int heavypath , string psf)
  {
      this->heavypath = heavypath;
      this->psf = psf;
  }

};

pair_ heavypath(vector<vector<edge>> &graph, int src ,int des , vector<bool> vis)
{
   if(src == des)
   {
       pair_ base( 0 , to_string(src) + " ");
       return base;
   }
    pair_   myans(-1,"");
    vis[src] = true;
    for(edge e : graph[src])
    {
        if(!vis[e.v])
        {
            pair_ recAns = heavypath(graph,e.v,des,vis);
            if(recAns.heavypath != -1 && recAns.heavypath + e.w > myans.heavypath )
            {
                myans.heavypath = recAns.heavypath + e.w;
                myans.psf = to_string(src) + recAns.psf;
            }

        }
    }
  vis[src] = false;

  return myans;
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


int main()
{   
    
    int v = 7;
    vector<vector<edge>> graph(v, vector<edge>());
    addedge(graph,0,1,10);
    addedge(graph,2,1,10);
    addedge(graph,2,3,20);
    addedge(graph,0,3,30);
    addedge(graph,3,4,10);
    addedge(graph,4,5,5);
    addedge(graph,5,6,40);
    addedge(graph,4,6,80);

  vector<bool> vis(v,false);
  pair_ ans = heavypath(graph,0,6,vis);
    cout<<ans.heavypath<<endl;
    
}
