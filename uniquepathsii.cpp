class Solution
{
public:
    //     int uniquepath_memo(vector<vector<int>> &grid, int sr,int sc, int er, int ec,vector<vector<int>> &dp,vector<vector<int>> &dir)
    //     {
    //         if(sr == er && sc == ec)
    //             return 1;

    //         if(dp[sr][sc] != 0)
    //             return dp[sr][sc];
    //         int count = 0;
    //         for(int d=0;d<dir.size();d++)
    //         {
    //             int r = sr + dir[d][0];
    //             int c = sc + dir[d][1];

    //             if(r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[r][c] == 0)
    //             {
    //               count +=   uniquepath_memo(grid,r,c,er,ec,dp,dir);

    //             }
    //         }

    //         return dp[sr][sc] = count;
    //     }

    int uniquepath_tabu(vector<vector<int>> &grid, int SR, int SC, int ER, int EC, vector<vector<int>> &dp, vector<vector<int>> &dir)
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

                    if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == 0)
                    {
                        count += dp[r][c];
                    }
                }

                dp[sr][sc] = count;
            }
        }

        return dp[SR][SC];
    }

    int uniquePathsWithObstacles(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
            return 0;
        vector<vector<int>> dir = {{1, 0}, {0, 1}};
        vector<vector<int>> dp(n, std::vector<int>(m, 0));

        return uniquepath_tabu(grid, 0, 0, n - 1, m - 1, dp, dir);
    }
};