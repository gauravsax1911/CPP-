
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

  
bool isBipartite(vector<vector<edge>> graph, vector<int> vis, int src)
{
    queue<int> que;
    que.push(src);
    int color = 0;
    vis[src] = 0;
    int level = 0;

    while(que.size()!=0)
    {
        int size = que.size();
        int colorcurr = level%2 == 0 ? 1 : 0 ;

        while(size-- > 0)
        {
            int idx = que.front();
            que.pop();

            for(edge e : graph[idx])
            {
                if(vis[e.v] != -1 && vis[e.v] == colorcurr)
                { continue ;}

                else if(vis[e.v] != -1 && vis[e.v] != colorcurr)
                { return false;}

                else{
                    que.push(e.v);
                    vis[e.v] = colorcurr;
                }

            }
            
        }
            level++;
    }

    return true;
}




void isBipartite_2 (vector<vector<edge>> graph, vector<int> vis, int src)
{
    queue<int> que;
    que.push(src);
    int color = 0;
    
    bool iscycle = false , isBipartite = true;
    
    while(que.size()!=0)
    {
        int size = que.size();
        while(size-- > 0)
        {
            int idx = que.front();
            que.pop();

            if(vis[idx] != -1)
            {
                 iscycle = true;
                 if(vis[idx] != color)
                 {isBipartite = false;}

                 continue;

            }
            vis[idx] = color;

            for(edge e : graph[idx])
            {
               if(e.v == -1)
                {
                  que.push(e.v);
                
                }

            }
            
        }
        color = (color + 1)%2;
           
    }


   if(isBipartite)
   {
       cout<<"GRAPH IS BIPARTITE"<<endl;

   }

   else
   {
       cout<<"GRAPH IS NON-BIPARTITE"<<endl;
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

    bfs_graph(graph, 0);

    return 0;
}