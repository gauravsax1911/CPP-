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

void display(vector<vector<edge>> &graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << "---->"
             << " ";
        for (edge e : graph[i])
        {
            cout << e.v << " ";
        }
        cout << endl;
    }
}

vector<int> Kahnsalgo(vector<vector<edge>> &graph, int n)
{
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (edge e : graph[i])
        {
            indegree[e.v]++;
        }
    }

    queue<int> que;
    vector<int> ans;
    vector<int> res;

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            que.push(i);
        }
    }

    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
           int idx = que.front();
           que.pop();
           ans.push_back(idx);

           for(edge e : graph[idx])
           {
               if(--indegree[e.v] == 0)
               {
                   que.push(e.v);
               }
           }

        }
    }

    cout<<"Program is a success"<<endl;
    return ans.size() == n ? ans : res;
}

int main()
{

    int n = 18;
    vector<vector<edge>> graph(n, std::vector<edge>());
    addedge(graph, 0, 1, 2);
    addedge(graph, 0, 5, 2);
    addedge(graph, 1, 2, 2);
    addedge(graph, 1, 15, 2);
    addedge(graph, 2, 3, 2);
    addedge(graph, 3, 4, 2);
    addedge(graph, 15, 16, 2);
    addedge(graph, 16, 12, 2);
    addedge(graph, 5, 13, 2);
    addedge(graph, 6, 5, 2);
    addedge(graph, 6, 7, 2);
    addedge(graph, 8, 7, 2);
    addedge(graph, 7, 14, 2);
    addedge(graph, 13, 14, 2);
    addedge(graph, 14, 11, 2);
    addedge(graph, 8, 9, 2);
    addedge(graph, 9, 10, 2);
    addedge(graph, 10, 11, 2);
    addedge(graph, 10, 17, 2);
    addedge(graph, 11, 12, 2);
    addedge(graph, 12, 17, 2);
    addedge(graph, 12, 4, 2);

    // display(graph);

    vector<int> res = Kahnsalgo(graph,n);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<"-->";
    }
    


}
