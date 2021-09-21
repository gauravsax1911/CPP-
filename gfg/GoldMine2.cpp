// Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int goldmine_dp_memo(int sr, int sc, vector<vector<int>> &dp, vector<vector<int>> &dir, int n, int m, vector<vector<int>> &grid)
    {
        if (sc == m - 1)
        {
            return dp[sr][sc] = grid[sr][sc];
        }

        if (dp[sr][sc] != -1)
        {
            return dp[sr][sc];
        }

        int maxgold = 0;

        for (vector<int> d : dir)
        {
            int r = sr + d[0];
            int c = sc + d[1];

            if (r >= 0 && r < n && c >= 0 && c < m)
            {
                maxgold = max(maxgold, goldmine_dp_memo(r, c, dp, dir, n, m, grid) + grid[sr][sc]);
            }
        }

        return dp[sr][sc] = maxgold;
    }

    int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<vector<int>> dir = {{1, 1}, {-1, 1}, {0, 1}};
        vector<vector<int>> dp(n, std::vector<int>(m, -1));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int res = goldmine_dp_memo(i,0,dp,dir,n,m,M);
            ans = max(res, ans);
        }

        return ans;
    }
};



int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> M(n, std::vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.maxGold(n, m, M) << endl;
    }

    return 0;
}