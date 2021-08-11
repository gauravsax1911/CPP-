#include<bits/stdc++.h>
using namespace std;
class edge{
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
    graph[v].push_back(edge(u, w));
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


void hamiltonianpath(vector<vector<edge>> &graph, int src , int origsrc, string psf , vector<string> &ans , int edges , int edgecnt, vector<bool> vis)
{

    if(edgecnt == edges)
    {
        psf += to_string(src);
        int idx = findedge(graph,origsrc,src);
        if(idx!= -1)
        { psf += "*" ;}

        ans.push_back(psf);

    }


    vis[src] = true;
    for(edge e: graph[src])
    {
        if(!vis[e.v])
        {
            hamiltonianpath(graph,e.v,origsrc,psf + to_string(src) , ans , edges , edgecnt + 1 ,vis);
        }
    }
    vis[src] = false;

}

// void display(vector<string> &ans)
// {
//     for(int i=0;i<ans.size();i++)
//     {
//         cout<<ans[i]<<endl;
//     }
// }



//Get all components


void dfs_compo(vector<vector<edge>> &graph, vector<bool> &vis, int src)
{
    vis[src] = true;
    for(edge e : graph[src])
    {
        if(!vis[e.v])
        {
            dfs_compo(graph,vis,e.v);
        }
    }


}


void getallcomponents(vector<vector<edge>> &graph)
{  int n = graph.size();
    vector<bool> vis(n,false);
    int components = 0;
    for(int i=0;i<n;i++)
    {
         if(!vis[i])
         {
             components++;
             dfs_compo(graph,vis,i);
         }
          
    }
   cout<<components<<endl;
}




int main()
{  int v = 10;
    vector<vector<edge>> graph(10,vector<edge>());

    addedge(graph,0,1,10);
    addedge(graph,2,1,10);
    addedge(graph,2,3,10);
    addedge(graph,0,3,10);

    addedge(graph,3,4,5);
    addedge(graph,4,5,10);
    addedge(graph,5,6,10);
    
    addedge(graph,4,6,10);
    
    
    addedge(graph,7,8,9);
    addedge(graph,8,9,1);
    addedge(graph,7,9,2);

  
//   vector<string> ans;
//   vector<bool> vis(7,false);
//   int edg = v-1;
//  hamiltonianpath(graph,0,0,"",ans,edg,0,vis);
//    display(ans);

   getallcomponents(graph);
//    cout<<x<<endl;
  
    return 0;
}