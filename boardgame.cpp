#include <bits/stdc++.h>
using namespace std;

int noofpaths(int sp, int ep)
{
    if (sp == ep)
    {
        return 1;
    }

    int count = 0;
    for (int i = 1; i <= 6 && sp + i <= ep; i++)
    {
        count += noofpaths(sp + i, ep);
    }

    return count;
}

int noofpaths_dp_memo(int sp, int ep, vector<int> &dp)
{
    if (sp == ep)
    {
        dp[ep] = 1;
        return 1;
    }

    if (dp[sp] != 0)
    {
        return dp[sp];
    }

    int count = 0;
    for (int i = 1; i <= 6 && sp + i <= ep; i++)
    {
        count += noofpaths_dp_memo(sp + i, ep, dp);
    }

    return dp[sp] = count;
}

int noofpaths_dp_tabu(int SP, int ep, vector<int> &dp)
{
    for (int sp = ep; sp >= SP; sp--)
    {
        if (sp == ep)
        {
            dp[sp] = 1;
            continue;
        }
        int count = 0;
        for (int i = 1; i <= 6 && sp + i <= ep; i++)
        {
            count += dp[sp + i];
        }

        dp[sp] = count;
    }

    return dp[SP];
}

int main()
{
    int ans = noofpaths(0, 10);
    vector<int> dp(11, 0);
    int ans2 = noofpaths_dp_memo(0, 10, dp);
    cout << ans << endl;
    cout << ans2 << endl;
    int ans3 = noofpaths_dp_tabu(0,10,dp);
    cout<<ans;
    return 0;
}