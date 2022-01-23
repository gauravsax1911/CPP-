#include <bits/stdc++.h>
using namespace std;
bool helper(vector<vector<int>> &maze, int sr, int sc, int er, int ec)
{
    int n = maze.size();
    int m = maze[0].size();

    vector<vector<bool>> vis(n, std::vector<bool>(m, false));
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    queue<int> que;
    que.push(sr * m + sc);
    vis[sr][sc] = true;
    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            int idx = que.front();
            int i = idx / m;
            int j = idx % m;
            que.pop();

            for (vector<int> d : dir)
            {
                int r = i;
                int c = j;
                while (r >= 0 && c >= 0 && r < n && c < m && maze[r][c] == 1)
                {
                    r += d[0];
                    c += d[1];
                }

                r -= d[0];
                c -= d[1];

                if (vis[r][c])
                {
                    continue;
                }

                vis[r][c] = true;
                que.push(r * m + c);
                if (r == er && c == ec)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
{
    int sr = start[0];
    int sc = start[1];

    int er = destination[0];
    int ec = destination[1];

    return helper(maze, sr, sc, er, ec);
}

//788 lintcode THE MAZE II

class pair_
{
public:
    int i;
    int j;
    int dfs;

    pair_(int i, int j, int dfs)
    {
        this->i = i;
        this->j = j;
        this->dfs = dfs;
    }
};
struct comp{
    bool operator()(pair_ &a,pair_ &b)
    {
        return a.dfs > b.dfs;
    }
};

bool helper(vector<vector<int>> &maze, int sr, int sc, int er, int ec)
{
    int n = maze.size();
    int m = maze[0].size();

    vector<vector<bool>> vis(n, std::vector<bool>(m, false));
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    vector<vector<int>> dis(n,std::vector<int>(m,(int)1e9));
    priority_queue<pair_, vector<pair_>,comp> que;
    que.push(pair_(sr,sc,0));
    dis[sr][sc] = 0;
    while (que.size() != 0)
    { 
        pair_ p = que.top();
        
       
    }

    return false;
}



int main()
{
    vector<vector<int>> maze = {
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0}};

    vector<int> start = {0, 4};
    vector<int> end = {4, 4};

    cout << hasPath(maze, start, end) << endl;
}