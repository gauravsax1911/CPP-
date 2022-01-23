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
void addedge(vector<vector<edge>> &graph, int u,int v, int w)
{
    graph[u].push_back(edge(v,w));
    graph[v].push_back(edge(u,w));
}
void dfs(vector<vector<edge>> &graph, int src, int des,vector<bool> vis, priority_queue<int,vector<int>> pq, int psf, int k,vector<int> &fans,int cnt)
{
    if(src == des)
    {  int x = k;
       if(cnt <= k)
       {
           fans[0] = 0;
           return;
       }
        while(x-- && pq.size() != 0)
        {
            psf -= pq.top();
            pq.pop();
        }

       fans[0] = min(fans[0],psf);
       return;
    }

    vis[src] = true;
    for(edge e : graph[src])
    {
        if(!vis[e.v])
        {
            pq.push(e.w);
            if(fans[0] == 0)
            {
                vis[src] = false;
                return;
            }
            dfs(graph,e.v,des,vis,pq,psf + e.w,k,fans,cnt + 1);
            
        }
    }
   
    vis[src] = false;  
}


vector<int> shortestpath_revisited(vector<vector<edge>> &graph, int k,int n)
{
   vector<int> ans;
   ans.push_back(0);
   vector<bool> vis(n+1,false);
   for(int i=2;i<= n;i++)
   {  
        vector<int> fans(1,(int)1e9);
        priority_queue<int, vector<int>> pq;
        dfs(graph,1,i,vis,pq,0,k,fans,0);
        ans.push_back(fans[0]);
   }
   return ans;
}


int main()
{ ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
  int n;
  cin>>n;
  int m;
  cin>>m;
  int k;
  cin>>k;
  vector<vector<edge>> graph(n+1,std::vector<edge>());
  for(int i=1;i<=m;i++)
  {
      int u,v,w;
      cin>>u>>v>>w;
      addedge(graph,u,v,w);
  }

  vector<int> res = shortestpath_revisited(graph,k,n);
  for(int x : res)
  {
      cout<<x<<" ";
  }

  return 0;

}