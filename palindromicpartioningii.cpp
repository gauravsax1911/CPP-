#include<bits/stdc++.h>
using namespace std;

int mincut(string s,int si,int ei,vector<int> &dp,vector<vector<bool>> &pdp)
{

    if(pdp[si][ei])
    {
        return 0;
    }

    if(dp[si] != -1)
    {
        return dp[si];
    }
    int minans = (int)1e8;
    for(int cuts = si;cuts<=ei;cuts++)
    {
        if(pdp[si][cuts])
        {
             minans = min(minans,mincut(s,cuts+1,ei,dp,pdp)+1);
        }
    }
    return dp[si] = minans;
}

int palindromic_partitions(string s)
{
    int n = s.length();

    // Using gap strategy to find the number of palindromic substrings in the string
    vector<vector<bool>> pdp(n,std::vector<bool>(n,false));

    for(int gap=0;gap<n;gap++)
    {
        for(int i=0,j=gap;j<n;j++,i++)
        {
            if(gap == 0)
            {
                 pdp[i][j] = true;
            }
            else if(gap == 1 && s[i] == s[j])
            {
                pdp[i][j] = true;
            }
            else{
                pdp[i][j] = (s[i] == s[j]) && pdp[i+1][j-1];
            }
        }
    }
   

   vector<int> dp(n+1,-1);

   return mincut(s,0,n-1,dp,pdp);

}
int main()
{
    string s;
    cin>>s;

}