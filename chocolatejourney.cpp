#include <bits/stdc++.h>
using namespace std;
class pair_
{
public:
    int src;
    int wsf;

    pair_(int src, int wsf)
    {
        this->src = src;
        this->wsf = wsf;
    }
};

class pair2
{
public:
    int city;
    int dis;

    pair2(int city, int dis)
    {
        this->city = city;
        this->dis = dis;
    }
};

struct comp2
{
    bool operator()(pair2 &a, pair2 &b)
    {
        return a.dis > b.dis;
    }
};

struct comp
{
    bool operator()(pair_ &a, pair_ &b)
    {
        return a.wsf > b.wsf;
    }
};
int chocolate_journey(vector<vector<pair<int, int>>> &graph, vector<int> &cities, int a, int b, int n, int x)
{
    int dist = 0;
    int flag1 = 0;
    for (pair<int, int> p1 : graph[a])
    {
        if (p1.first == b)
        {
            dist += p1.second;
            flag1 = 1;
            break;
        }
    }
    // return flag1;

    priority_queue<pair_, vector<pair_>, comp> pq;
    vector<bool> vis(n + 1, false);
    vector<int> dis(n + 1, (int)1e8);
    pq.push(pair_(a, 0));
    while (pq.size() != 0)
    {
        pair_ p = pq.top();
        pq.pop();

        if (vis[p.src])
        {
            continue;
        }

        vis[p.src] = true;
        dis[p.src] = p.wsf;

        for (pair<int, int> road : graph[p.src])
        {
            if (!vis[road.first] && p.wsf + road.second < dis[road.first])
            {
                pq.push(pair_(road.first, p.wsf + road.second));
                dis[road.first] = p.wsf + road.second;
            }
        }
    }
    // for(int i=0;i<n+1;i++)
    // {
    //     cout<<dis[i]<<"  ";
    // }

    vector<pair2> pq1;
    for (int cty : cities)
    {
        if (dis[cty] != (int)1e8)
        {
            pq1.push_back(pair2(cty, dis[cty]));
            // cout<<cty<<"   "<<dis[cty]<<endl;
        }
    }

    vector<int> ans(1, -1);
    for (int i = 0; i < pq1.size(); i++)
    {
        pair2 p = pq1[i];
        int ans1 = p.dis;
        int ans2 = p.dis;
        int flag = 0;
        for (pair<int, int> p1 : graph[p.city])
        {
            if (p1.first == b)
            {
                ans2 += p1.second;
                flag = 1;
                break;
            }
        }

        ans1 *= 2;
        ans1 += dist;

        if (flag == 0 && flag1 == 0)
        {
            continue;
        }

        if (flag == 0 && flag1 == 1)
        {
            ans.push_back(ans1);
        }

        if (flag == 1 && flag1 == 0)
        {
            ans.push_back(ans2);
        }

        if (flag == 1 && flag1 == 1)
        {

            int m = min(ans1, ans2);
            ans.push_back(m);
        }
    }
    if (ans.size() == 1)
    {
        return -1;
    }
    sort(ans.begin(), ans.end());

    int time = ans[1];
    return time > x ? -1 : time;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, x;
    cin >> n >> m >> k >> x;

    vector<int> cities;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        cities.push_back(x);
    }
    vector<vector<pair<int, int>>> graph(n + 1, std::vector<pair<int, int>>());
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    int a, b;
    cin >> a >> b;

    int ans = chocolate_journey(graph, cities, a, b, n, x);
    cout << ans << endl;
}
