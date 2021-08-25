#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    class pair_
    {
    public:
        int src;
        int wsf;
        int edg;
        pair_(int src, int wsf, int edg)
        {
            this->src = src;
            this->wsf = wsf;
            this->edg = edg;
        }
    };

    struct comp
    {
        bool operator()(pair_ &a, pair_ &b)
        {
            return a.wsf > b.wsf;
        }
    };

    int dijikstra(vector<vector<pair<int, int>>> &graph, int src, int des, int k, int n)
    {
        int edges = k + 1;
        priority_queue<pair_, vector<pair_>, comp> pq;
        pq.push(pair_(src, 0, 0));
        vector<int> dis(n, (int)1e9);
        vector<bool> vis(n, false);

        while (pq.size() != 0)
        {
            pair_ p = pq.top();
            pq.pop();

            vis[p.src] = true;
            for (pair<int, int> pr : graph[p.src])
            {

                if (p.edg + 1 <= edges)
                {
                    if (pr.second + p.wsf < dis[pr.first])]
                        {
                            dis[pr.first] = pr.second + p.wsf;
                        }
                    pq.qush(pair_(pr.first, pr.second + p.wsf, p.edg + 1));
                }

                dis[pr.first] = pr.second + p.wsf;
                pq.push(pair_(pr.first, pr.second + p.wsf, p.edg + 1));
            }
        }
    }

    return dis[des] == (int)1e9 ? -1 : dis[des];
}

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{

    vector<vector<pair<int, int>>> graph(n, std::vector<pair<int, int>>());
    for (vector<int> v : flights)
    {
        graph[v[0]].push_back({v[1], v[2]});
    }
    return dijikstra(graph, src, dst, k, n);
}
};

int main()
{
    
}