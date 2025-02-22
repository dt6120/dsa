#include <bits/stdc++.h>

using namespace std;

int maxSumRecursion(vector<int> &nums, int i, vector<int> &dp)
{
    if (i < 0)
    {
        return 0;
    }
    if (i == 0)
    {
        return nums[0];
    }

    if (dp[i] != -1)
    {
        return dp[i];
    }

    return dp[i] = max(nums[i] + maxSumRecursion(nums, i - 2, dp), maxSumRecursion(nums, i - 1, dp));
}

int maxSumTabulation(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 1);

    dp[0] = 0;
    dp[1] = nums[0];

    for (int i = 2; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
    }

    return dp[n];
}

int main()
{
    vector<int> nums = {2, 1, 4, 9};
    int n = nums.size();
    vector<int> dp(n, -1);

    cout << maxSumRecursion(nums, n - 1, dp) << endl;
    cout << maxSumTabulation(nums) << endl;
}
