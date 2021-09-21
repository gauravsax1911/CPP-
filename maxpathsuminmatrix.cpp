#include <bits/stdc++.h>
using namespace std;

int maxCostPath_recursive(int i, int j, vector<vector<int>> &grid, int psf, int n, int m)
{

    if (j < 0 || i >= n || j >= m)
    {
        return psf;
    }

    return max(maxCostPath_recursive(i + 1, j - 1, grid, psf + grid[i][j], n, m), max(maxCostPath_recursive(i + 1, j + 1, grid, psf + grid[i][j], n, m), maxCostPath_recursive(i + 1, j, grid, psf + grid[i][j], n, m)));
}

int maxCostPath_dp_tabu(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<int>> dp(n, std::vector<int>(n, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == n - 1)
            {
                dp[i][j] = grid[i][j];
                continue;
            }
            int ans = 0;
            if (j == 0)
            {
                ans = max(dp[i + 1][j], dp[i + 1][j + 1]);
            }
            else if (j == n - 1)
            {
                ans = max(dp[i + 1][j], dp[i + 1][j - 1]);
            }
            else
            {
                ans = max(dp[i + 1][j - 1], max(dp[i + 1][j], dp[i + 1][j + 1]));
            }
            dp[i][j] = ans + grid[i][j];
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = max(res, grid[0][i]);
    }
    return res;
}

int maxCostPath_dp_memo(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp, int n, int m,vector<vector<int>> &dir)
{
    if(i==n-1)
    {
       return  dp[i][j] = grid[i][j];
    }

    if(dp[i][j]  != -1)
    {
        return dp[i][j];
    }
     int maxPath = 0;
    for(vector<int> d : dir)
    {
        int r = i + d[0];
        int c = j + d[1];

        if(r>=0 && r<n && c>=0 && c<n)
        {
            maxPath = max(maxPath,maxCostPath_dp_memo(r,c,grid,dp,n,m,dir) + grid[i][j]);
        }

    }

    return dp[i][j] = maxPath;
}

int maxCostPath(int n, int m, vector<vector<int>> &grid)
{
    int ans = 0;
    vector<vector<int>> dir = {{1,0},{1,1},{1,-1}};
    vector<vector<int>> dp(n, std::vector<int>(m, -1));
    for (int j = 0; j < m; j++)
    {
        ans = max(ans, maxCostPath_dp_memo(0, j, grid, dp, n, m,dir));
    }
    for(vector<int> v : dp)
    {
        for(int x : v)
        {
            cout<<x<<"  ";
        }
        cout<<endl;
    }
    cout<<"FINAL ANS ";
    return ans;
}

int main()
{
    int n = 3;
    int m = 3;

    vector<vector<int>> grid = {{1, 2, 3}, {4, 1, 6}, {3, 5, 2}};

    
    cout << maxCostPath(n, m, grid);
}