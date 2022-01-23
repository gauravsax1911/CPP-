#include <bits/stdc++.h>
using namespace std;
bool haspath_helper(vector<vector<int>> &maze, int sr, int sc, int er, int ec)
{
    queue<int> que;
    int n = maze.size();
    int m = maze[0].size();
    vector<vector<bool>> vis(n, std::vector<bool>(m, false));
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    que.push(sr * m + sc);
    vis[sr][sc] = true;
    while (que.size() != 0)
    {
        int size = que.size();

        while (size-- > 0)
        {
            int idx = que.front();
            que.pop();
            int i = idx / m;
            int j = idx % m;

            for (int d = 0; d < dir.size(); d++)
            {
                int r = i;
                int c = j;

                while (r >= 0 && c >= 0 && r < n && c < m && maze[r][c] == 0)
                {
                    r += dir[d][0];
                    c += dir[d][1];
                }

                r -= dir[d][0];
                c -= dir[d][1];

                if (vis[r][c])
                {
                    continue;
                }

                vis[r][c] = true;
                if (r == er && c == ec)
                {
                    return true;
                }

                que.push(r * m + c);
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

    return haspath_helper(maze,sr,sc,er,ec);
}

int main()
{


}