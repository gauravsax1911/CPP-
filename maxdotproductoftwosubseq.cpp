#include <bits/stdc++.h>
using namespace std;

int maxDotProduct(vector<int> &nums1, vector<int> &nums2, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 || m == 0)
    {
        return dp[n][m] = -(int)1e8;
    }

    if (dp[n][m] != -(int)1e9)
    {
        return dp[n][m];
    }

    int val = nums1[n - 1] * nums2[m - 1];
    int includeboth = maxDotProduct(nums1, nums2, n - 1, m - 1, dp) + val;
    int include_num1 = maxDotProduct(nums1, nums2, n - 1, m, dp);
    int include_num2 = maxDotProduct(nums1, nums2, n, m - 1, dp);
    vector<int> ::iterator it;
    vector<int> v = {val,include_num1,includeboth,include_num2};
    it = std::max_element(v.begin(),v.end());


    return dp[n][m] = (int)(*it);
}

int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    vector<vector<int>> dp(n + 1, std::vector<int>(m + 1, -(int)1e9));
    return maxDotProduct(nums1, nums2, n, m, dp);
}

int main()
{
    vector<int> nums1 = {2,1,-2,5};
    vector<int> nums2 =  {3,0,-6};

    cout<<maxDotProduct(nums1,nums2);
}