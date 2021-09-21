#include <bits/stdc++.h>
using namespace std;
int mazepath_recursive(int sr, int sc, int er, int ec, vector<vector<int>> &dir, int n, int m)
{
    if (sr == er && sc == ec)
    {
        return 1;
    }
    int count = 0;
    for (int d = 0; d < dir.size(); d++)
    {
        int r = sr + dir[d][0];
        int c = sc + dir[d][1];

        if (r >= 0 && c >= 0 && r < n && c < m)
        {
            count += mazepath_recursive(r, c, er, ec, dir, n, m);
        }
    }

    return count;
}

int mazepath_onejump_dp_memo(int sr, int sc, int er, int ec, vector<vector<int>> &dir, vector<vector<int>> &dp)
{

    if (sr == er && sc == ec)
    {
        return 1;
    }

    if (dp[sr][sc] != 0)
    {
        return dp[sr][sc];
    }

    int count = 0;

    for (int d = 0; d < dir.size(); d++)
    {
        int r = sr + dir[d][0];
        int c = sc + dir[d][1];

        if (r >= 0 && c >= 0 && r < dp.size() && c < dp[0].size())
        {
            count += mazepath_onejump_dp_memo(r, c, er, ec, dir, dp);
        }
    }

    return dp[sr][sc] = count;
}

int mazepath_onejump_dp_tabu(int SR, int SC, int ER, int EC, vector<vector<int>> &dir, vector<vector<int>> &dp)
{

    for (int sr = ER; sr >= SR; sr--)
    {
        for (int sc = EC; sc >= SC; sc--)
        {
            if (sr == ER && sc == EC)
            {
                dp[sr][sc] = 1;
                continue;
            }

            int count = 0;

            for (int d = 0; d < dir.size(); d++)
            {
                int r = sr + dir[d][0];
                int c = sc + dir[d][1];

                if (r >= 0 && c >= 0 && r < dp.size() && c < dp[0].size())
                {
                    count += dp[r][c];
                }
            }

            dp[sr][sc] = count;
        }
    }

    return dp[SR][SC];
}

int main()
{
    int n, m;
    n = 3;
    m = 3;
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {1, 1}};
    vector<vector<int>> dp(n, std::vector<int>(m, 0));
    cout << "RECURSIVE ANSWER----->  " << mazepath_recursive(0, 0, n - 1, m - 1, dir, n, m) << endl;
    cout << "ANSWER FOR MEMOIZATION METHOD --->   " << mazepath_onejump_dp_memo(0, 0, n - 1, m - 1, dir, dp) << endl;
    cout << "ANSWER FOR TABULATION METHOD---->  " << mazepath_onejump_dp_tabu(0, 0, n - 1, m - 1, dir, dp) << endl;
}