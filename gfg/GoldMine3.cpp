#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int goldmine_dp_tabu(int n, int col, vector<vector<int>> &m)
    {
        vector<vector<int>> dp(n + 1, std::vector<int>(col + 1, 0));
        int fans = 0;
        for (int j = col - 1; j >= 0; j--)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                if (j == col - 1)
                {
                    dp[i][j] = m[i][j];
                    continue;
                }

                int ans = 0;

                if (i == 0)
                {
                    ans = max(dp[i + 1][j + 1], dp[i][j + 1]);
                }
                else
                {
                    ans = max(dp[i - 1][j + 1], max(dp[i][j + 1], dp[i + 1][j + 1]));
                }

                dp[i][j] = ans + m[i][j];
                if (j == 0)
                {
                    fans = max(fans, dp[i][j]);
                }
            }
        }
        return fans;
    }

    int maxGold(int n, int m, vector<vector<int>> M)
    {
       
        return goldmine_dp_tabu(n,m,M);
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