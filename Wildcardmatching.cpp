#include <bits/stdc++.h>
using namespace std;

bool wildcardmatching_recursive(string s, string t, int n, int m)
{

    if (m == 0 || n == 0)
    {
        if (m == 0 && n == 0)
        {
            return false;
        }

        else if (m == 1 && t[m - 1] == '*')
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    if (s[n - 1] == t[m - 1] || t[m - 1] == '?')
    {
        return wildcardmatching_recursive(s, t, n - 1, m - 1);
    }
    else if (s[n - 1] != t[m - 1] && t[m - 1] == '*')
    {
        bool res = false;
        res = res || wildcardmatching_recursive(s, t, n - 1, m - 1);
        res = res || wildcardmatching_recursive(s, t, n - 1, m);
        return res;
    }
    else
    {
        return false;
    }
}

bool wildcardmatching_dp_memo(string s, string t, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 || m == 0)
    {
        if (n == 0 && m == 0)
        {
            return dp[n][m] = false;
        }

        else if (m == 1 && t[n - 1] == '*')
        {
            return dp[n][m] = false;
        }

        else if (n == 0 && m != 0 && t[m - 1] == '*')
        {
            int x = m;
            int count = 0;
            while (x > 0)
            {
                count += t[x - 1] == '*';
                x--;
            }
            return dp[n][m] = count == m ? 1 : 0;
        }

        else
        {
            return dp[n][m] = 0;
        }
    }

    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    if (s[n - 1] == t[m - 1] || t[m - 1] == '?')
    {
        return dp[n][m] = wildcardmatching_dp_memo(s, t, n - 1, m - 1, dp);
    }
    else if (t[m - 1] == '*')
    {
        bool res = false;
        res = res || wildcardmatching_dp_memo(s, t, n - 1, m, dp);
        res = res || wildcardmatching_dp_memo(s, t, n, m - 1, dp);
        return dp[n][m] = res;
    }

    else
    {
        dp[n][m] = false;
    }
}
int wildcardmatching_dp_tabu(string s, string t, int N, int M, vector<vector<int>> &dp)
{
    for (int m = 0; m < M; m++)
    {
        for (int n = 0; n < N; n++)
        {

            if (n == 0 || m == 0)
            {
                if (n == 0 && m == 0)
                {
                    dp[n][m] = 1;
                    continue;
                }

                else if (m == 1 && t[n - 1] == '*')
                {
                    dp[n][m] = 0;
                    continue;
                }

                else if (n == 0 && m != 0 && t[m - 1] == '*')
                {
                    int x = m;
                    int count = 0;
                    while (x > 0)
                    {
                        count += t[x - 1] == '*';
                        x--;
                    }
                    dp[n][m] = count == m ? 1 : 0;
                    continue;
                }

                else
                {
                    dp[n][m] = 0;
                    continue;
                }
            }

            if (s[n - 1] == t[m - 1] || t[m - 1] == '?')
            {
                dp[n][m] = dp[n - 1][m - 1]; //wildcardmatching_dp_memo(s, t, n - 1, m - 1, dp);
            }
            else if (t[m - 1] == '*')
            {
                bool res = false;
                res = res || dp[n - 1][m] == 1; //wildcardmatching_dp_memo(s, t, n - 1, m, dp);
                res = res || dp[n][m - 1] == 1; //wildcardmatching_dp_memo(s, t, n, m - 1, dp);
                return dp[n][m] = res;
            }

            else
            {
                dp[n][m] = 0;
            }
        }
    }

    return dp[N][M];
}

bool wildcardmatching(string s, string t)
{
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n + 1, std::vector<int>(m + 1, -1));
    return wildcardmatching_dp_tabu(s, t, n, m, dp);
}

int main()
{
    string s = "";
    string t = "*****";

    cout << wildcardmatching(s, t);
}