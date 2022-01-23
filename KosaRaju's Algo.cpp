void dfs_01(int src, vector<vector<edge>> &graph, vector<int> &st, vector<bool> &vis)
{
    vis[src] = true;
    for (edge e : graph[src])
    {
        if (!vis[e.v])
        {
            dfs_01(e.v, graph, st, vis);
        }
    }
    st.push_back(src);
}
void dfs_02(vector<vector<edge>> &graph, int src, vector<bool> vis)
{
    vis[src] = true;
    for (edge e : graph[src])
    {
        if (!vis[e.v])
        {
            dfs_02(graph, e.v, vis);
        }
    }
}

void KosaRajus_Algo(vector<vector<edge>> &graph, int n)
{
    vector<bool> vis(n, false);
    vector<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs_01(i, graph, st, vis);
        }
    }

    vis.clear();
    vis.resize(n, false);

    // Inverse of graph
    vector<vector<edge>> newgraph(n, std::vector<edge>());
    for (int i = 0; i < graph.size(); i++)
    {
        for (edge e : graph[i])
        {
            newgraph[e.v].push_back(edge(i, e.w));
        }
    }
    int count = 0;
    for (int i = st.size() - 1; i >= 0; i--)
    {
        if (!vis[st[i]])
        {
            dfs_02(newgraph, st[i], vis);
            count++;
        }
    }

    cout << count << endl;
}