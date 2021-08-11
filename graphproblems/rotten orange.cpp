#include <bits/stdc++.h>
using namespace std;
int (vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    queue<int> que;

    int time = 0, orangecount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                que.push(i * m + j);
            }
            else if (grid[i][j] == 1)
            {
                orangecount++;
            }
        }
    }

    vector<vector<int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

    if (orangecount == 0)
    {
        return 0;
    }
    int time = 0;
    while (que.size() != 0)
    {
        int size = que.size();

        while (size--)
        {
            int idx = que.front();

            int sr = idx / m;
            int sc = idx % m;
            que.pop();

            for (int i = 0; i < dir.size(); i++)
            {
                int r = sr + dir[i][0];
                int c = sc + dir[i][1];

                if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1)
                {
                    grid[r][c] = 2;
                    que.push(r * m + c);
                    orangecount--;
                    if (orangecount == 0)
                    {
                        return time + 1;
                    }
                }
            }
        }

        time++;
    }

    return -1;
}

int main()
{
}