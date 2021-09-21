#include<bits/stdc++.h>
using namespace std;
int m = (int)1e9+7;
long decodeways_2(string s,int idx,vector<int> &dp)
{   int n = s.length();
    if(idx == n)
    {
        dp[idx] = 1;
        return 1;
    }

    
    if(dp[idx] != -1)
    {return dp[idx];}

    if(s[idx] == '0')
    {return dp[idx] =0;}


    long count = 0;

    if(s[idx] == '*')
    {
        count += 9* (decodeways_2(s,idx+1,dp)%m);
        if(idx  < n-1)
        {
            
            char ch = s[idx + 1];
            if(ch >= '0' && ch<='6')
            {
               count += 2* (decodeways_2(s,idx+2,dp) %m);
            }
            else if(ch >= '7' && ch<= '9')
            {
                 count += (decodeways_2(s,idx+2,dp) %m);
            }

            else{
              count += 15*(decodeways_2(s,idx+2,dp)%m);
            }
        }
    }

    else{
        count += (decodeways_2(s,idx+1,dp)%m);
        char ch = s[idx];
        if(idx < n-1)
        {
            char c = s[idx + 1];
            if( c == '*' && ch == '1')
            {
                count += 9*(decodeways_2(s,idx+2,dp)%m);
            }

            else if( c == '*' && ch == '2')
            {
                count += 6*(decodeways_2(s,idx+2,dp)%m);
            }
            else if(c != '*'){
                int num = (ch-'0')*10 + (c-'0');
                if(num<=26)
                {
                    count += decodeways_2(s,idx+2,dp)%m;
                }
            }
        }
    }

    return dp[idx] = count;

}

long decodeways(string s)
{

    int n = s.length();
    vector<int> dp(n,-1);

    return decodeways_2(s,0,dp);
}

int main()
{
    string s = "2*";
    cout<<decodeways(s);

}