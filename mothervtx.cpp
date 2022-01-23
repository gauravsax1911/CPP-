#include<bits/stdc++.h>
using namespace std;
void dfs_01(vector<vector<int>> &graph, int src, vector<int> st,vector<bool> &vis)
{
    vis[src] = true;
    for(int x : graph[src])
    {
        if(!vis[x])
        {
            dfs_01(graph,x,st,vis);
        }
    }
    st.push_back(src);
}

void dfs_02(vector<vector<int>> &graph,int src,vector<bool> vis, vector<int> &count)
{
    vis[src] = true;
    for(int x : graph[src])
    {
        if(!vis[x])
        {
            count[0]++;
            dfs_02(graph,x,vis,count);
        }
    }
}

int mother_vertex(vector<vector<int>> &graph, int n)
{
    vector<bool> vis(n,false);
    vector<int> st;
    int mthrvtx = -1;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs_01(graph,i,st,vis);
            mthrvtx = i;
        }
    }

    vis.clear();
    vis.resize(n,false);
    vector<int> count(1,0);
    dfs_02(graph,mthrvtx,vis,count);
    if(count[0] == n-1)
    {
        return mthrvtx;
    }

    else
    {
        return -1;
    }

}

int main()
{

}