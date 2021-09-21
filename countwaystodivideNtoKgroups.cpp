#include<bits/stdc++.h>
using namespace std;
int waystodivide_dp_memo(int n, int k, vector<vector<int>> &dp)
{
    if(n == k || k == 1)
    {
        return dp[n][k] = 1;
    }

    if(dp[n][k] != -1)
    {
        return dp[n][k];
    }

    int selfGroup = waystodivide_dp_memo(n-1,k-1,dp);
    int AnyGroup = waystodivide_dp_memo(n-1,k,dp)*k;

    return dp[n][k] = selfGroup + AnyGroup;
}

int waystodivide(int n, int k)
{
    vector<vector<int>> dp(n+1,std::vector<int>(k+1,-1));
    
    int ans = waystodivide_dp_memo(n,k,dp);
    for(vector<int> d : dp)
    {
        for(int x : d)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return ans;

}
int main()
{
    int n= 8, k=4;

    cout<<waystodivide(n,k);

}