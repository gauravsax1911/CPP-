#include <bits/stdc++.h>
using namespace std;

void coinexchange_recursive(int n, int m, vector<int> &s, set<vector<int>> &ans, vector<int> psf)
{
    if (n == 0)
    {
        sort(psf.begin(), psf.end());
        ans.insert(psf);
        return;
    }

    for (int i = 0; i < m; i++)
    {
        if (n - s[i] >= 0)
        {
            psf.push_back(s[i]);
            coinexchange_recursive(n - s[i], m, s, ans, psf);
            psf.pop_back();
        }
    }
    return;
}


int coinexchange_recursive_02(int n,int m, vector<int> s)
{
    int ans = 0;
    for(int i=0;i<m;i++)
    {
        if(n-s[i] >0)
        {
           ans += coinexchange_recursive_02(n-s[i],m,s);
        }
        else if(n-s[i] == 0)
        {
           ans++;     
        }
        else
        {
                continue;
        }
    }
    
    return ans;
}


int coinexchange_dp(int n,int m ,vector<int> s)
{
    vector<int> dp(n+1,0);
    dp[0] = 1;
    for(int i=0;i<m;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(j-s[i] < 0)
            {continue;}
            dp[j] += dp[j-s[i]];
        }
    }
    return dp[n];
}



int coinexchange(int n, int m, vector<int> s)
{
    
    return coinexchange_dp(n, m, s);  
}



int main()
{
    int n = 10;
    int m = 4;
    vector<int> s = {2,3,5,6};
    cout<<coinexchange(n,m,s);
    return 0;
}