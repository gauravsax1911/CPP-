#include <bits/stdc++.h>
using namespace std;
int m = (int)1e9 + 7;
int friendspairing_recursive(int n)
{
  if (n <= 2)
  {
    return n;
  }

  return (n - 1) * friendspairing_recursive(n - 2) + friendspairing_recursive(n - 1);
}

int friendpairing_dp_tabu(int n)
{
  vector<int> dp((int)1e4 + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    if (i <= 2)
    {
      dp[i] = i;
      continue;
    }

    dp[i] = (((i - 1) * dp[i - 2]) + dp[i - 1]);
  }
  return dp[n];
}

// Solution 2

int countFriendsPairings(int n,vector<long> &dp) 
{
  if(n==0)
  { 
    dp[n] = 1;
    return 1;
  }

  if(dp[n] != -1)
  {
    return dp[n];
  }

  int single = countFriendsPairings(n-1,dp);
  int pairUp = n - 2 >=0 ? countFriendsPairings(n-2,dp)*(n-1) : 0;

  return dp[n] = (single+pairUp)%m;
}


int main()
{
  int n = 5;

  cout << "Recursive Solution " << friendspairing_recursive(n) << endl;
  cout << "Tabulation Solution " << friendpairing_dp_tabu(n) << endl;
  vector<long> dp(n+1,-1);
  cout<<"Solution diff :"<<countFriendsPairings(n,dp);
}