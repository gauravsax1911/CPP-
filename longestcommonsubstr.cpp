#include <bits/stdc++.h>
using namespace std;

int lcsubstr_dp_tabu(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
    int len = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            if (s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                len = max(len, dp[i][j]);
            }
        }
    }

    return len;
}

int main()
{
    string s1 = "abcdxyzeek";
    string s2 = "xyzabcd";

    cout<<lcsubstr_dp_tabu(s1,s2);
}