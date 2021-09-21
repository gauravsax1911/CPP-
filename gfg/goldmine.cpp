#include <bits/stdc++.h>
using namespace std;

// int goldmine_recursive(int i, int j, vector<vector<int>> &m, int psf, int n, int col)
// {
//     if (i < 0 || i >= n || j >= col)
//     {
//         return psf;
//     }

//     return max(goldmine_recursive(i + 1, j + 1, m, psf + m[i][j], n, col), max(goldmine_recursive(i, j + 1, m, psf + m[i][j], n, col), goldmine_recursive(i - 1, j + 1, m, psf + m[i][j], n, col)));
// }


int goldmine_dp_tabu(int n,int col,vector<vector<int>> &m)
{
    vector<vector<int>> dp(n+1,std::vector<int>(col+1,0));
    int fans = 0;
    for(int j=col-1;j>=0;j--)
    {
        for(int i=n-1;i>=0;i--)
        {
            if(j == col-1)
            {
                dp[i][j] = m[i][j];
                continue;
            }

            int ans = 0;
            
            if(i==0)
            {
                ans = max(dp[i+1][j+1],dp[i][j+1]);
            }
            else{
                ans = max(dp[i-1][j+1],max(dp[i][j+1],dp[i+1][j+1]));
            }

            dp[i][j] = ans + m[i][j];
            if(j==0)
            {
                fans = max(fans,dp[i][j]);
            }
        }
    }
    return fans;
}


int goldmine_dp_memo(int sr, int sc,vector<vector<int>> &dp,vector<vector<int>> &dir, int n, int m,vector<vector<int>> &grid)
{
    if(sc == m-1)
    {
       return  dp[sr][sc] = grid[sr][sc];
    }

    if(dp[sr][sc] != -1)
    {
        return dp[sr][sc];
    }
   
    int maxgold = 0;
    

    for(vector<int> d : dir)
    {
        int r = sr + d[0];
        int c = sc + d[1];

        if(r>=0 && r<n && c>=0 && c<m)
        {
            maxgold = max(maxgold,goldmine_dp_memo(r,c,dp,dir,n,m,grid)+ grid[sr][sc]);
        }
    }
 
    return dp[sr][sc] = maxgold;
}
int goldmine(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<int>> dir = {{1,1},{-1,1},{0,1}};
    vector<vector<int>> dp(n,std::vector<int>(m,-1));
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        int res = goldmine_dp_memo(i,0,dp,dir,n,m,grid);
        ans = max(res,ans);
    }
//   int ans = goldmine_dp_tabu(n,col,m);
    return ans;
}

int main()
{
    int n = 3;
    int m = 3;

    vector<vector<int>> grid = {{1, 3, 3},
                   {2, 1, 4},
                  {0, 6, 4}};
   
    

    int ans = goldmine(n,m,grid);
    cout<<ans;
}