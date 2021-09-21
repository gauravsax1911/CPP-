#include <bits/stdc++.h>
using namespace std;

int LCS_recursive(string s1, string s2, int i, int j)
{
    if (i >= s1.length() || j >= s2.length())
    {
        return 0;
    }
    char c1 = s1[i];
    char c2 = s2[j];

    int ans = 0;
    if (c1 == c2)
    {
        ans = LCS_recursive(s1, s2, i + 1, j + 1) + 1;
    }
    else
    {

        int include_s1 = LCS_recursive(s1, s2, i + 1, j);
        int include_s2 = LCS_recursive(s1, s2, i, j + 1);

        ans = max(include_s1, include_s2);
    }

    return ans;
}

int LCS_dp_memo(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{

    if (i >= s1.length() || j >= s2.length())
    {
        return 0;
    }

    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    char c1 = s1[i];
    char c2 = s2[j];

    if (c1 == c2)
    {
        return dp[i][j] = LCS_dp_memo(s1, s2, i + 1, j + 1,dp) + 1;
    }
    else
    {

        int include_s1 = LCS_dp_memo(s1, s2, i + 1, j,dp);
        int include_s2 = LCS_dp_memo(s1, s2, i, j + 1,dp);

        return dp[i][j] =  max(include_s1, include_s2);
    }

}


int LCS_dp_tabu(string s1,string s2)
{
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n+1,std::vector<int>(m+1,0));

    for(int i = n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            
            char c1 = s1[i];
            char c2 = s2[j];

            if(c1 == c2)
            {
                dp[i][j] = dp[i+1][j+1] + 1;
            }
            else
            {
              dp[i][j] = max(dp[i+1][j],dp[i][j+1]);   
            }
        }
    }

   return dp[0][0];
}

int main()
{
    string s1 = "acbaed";
    string s2 = "abcadf";
    cout << LCS_recursive(s1, s2, 0, 0) << endl;
    cout<<LCS_dp_tabu(s1,s2)<<endl;
}