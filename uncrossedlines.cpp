#include <bits/stdc++.h>

using namespace std;
int maxuncrossedlines_recursive_02(vector<int> &nums1, vector<int> &nums2, int sp, int pt)
{
    if (sp >= nums1.size())
    {
        return 0;
    }
    int ans = 0;
    for (int j = 0; j < nums2.size(); j++)
    {
        if (nums1[sp] == nums2[j] && pt < j)
        {

            int res = maxuncrossedlines_recursive_02(nums1, nums2, sp + 1, j) + 1;
            ans = max(ans, res);
        }
    }

    int fans = maxuncrossedlines_recursive_02(nums1, nums2, sp + 1, pt);
    ans = max(fans, ans);
    return ans;
}

int maxuncrossedlines_dp_memo(vector<int> &nums1, vector<int> &nums2, int sp, int pt, vector<vector<int>> &dp)
{
    if (sp >= nums1.size())
    {
        return 0;
    }

    if (dp[sp][abs(pt)] != -1)
    {
        return dp[sp][abs(pt)];
    }

    int ans = 0;
    for (int j = 0; j < nums2.size(); j++)
    {
        if (nums1[sp] == nums2[j] && pt < j)
        {

            int res = maxuncrossedlines_dp_memo(nums1, nums2, sp + 1, j, dp) + 1;
            ans = max(ans, res);
        }
    }

    int fans = maxuncrossedlines_dp_memo(nums1, nums2, sp + 1, pt, dp);
    ans = max(fans, ans);
    return dp[sp][abs(pt)] = ans;
}

int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    // vector<int> dp(n,-1);
    vector<vector<int>> dp(501, std::vector<int>(501, -1));
    // return maxuncrossedlines_recursive_02(nums1, nums2, 0, -501);
    return maxuncrossedlines_dp_memo(nums1, nums2, 0, -1, dp);
}

int maxuncrossedlines_dp_tabu(vector<int> &nums1, vector<int> &nums2)
{
    int pt = -501;
    vector<vector<int>> dp(501,std::vector<int>(501,-1));
    for (int i = nums1.size(); i >= 0; i--)
    {
        for (int j = 0; j < nums1.size(); j++)
        {
            if (i == nums1.size())
            {
                dp[i][abs(pt)] = 0;
                continue;
            }
            int ans = 0;
            if (nums1[i] == nums2[j] && pt < j)
            {
                int fans = dp[sp + 1][abs(j)] + 1;
                fans = max(ans, fans);
            }
        }

        int fans = dp[sp + 1][abs(pt)];
        ans = max(ans, fans);
        dp[i][abs(pt)] = ans;
    }

    return dp[0][501];
}

int main()
{
    vector<int> nums1 = {10, 5, 3, 4, 6, 7, 2, 9, 15};
    vector<int> nums2 = {2, 3, 4, 6, 7, 5, 9, 10, 15};

    cout << maxUncrossedLines(nums1, nums2);
}