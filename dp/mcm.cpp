#include <bits/stdc++.h>

using namespace std;

int mcmRecursion(vector<int> &nums, int i, int j, vector<vector<int>> &dp)
{
    if (i >= j)
    {
        return 0;
    }

    if (dp[i][j] != INT_MAX)
    {
        return dp[i][j];
    }

    int minCost = INT_MAX;

    for (int k = i; k <= j - 1; k++)
    {
        int cost = mcmRecursion(nums, i, k, dp) +
                   mcmRecursion(nums, k + 1, j, dp) +
                   nums[i - 1] * nums[k] * nums[j];

        minCost = min(minCost, cost);
    }

    return dp[i][j] = minCost;
}

int mcmTabulation(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int minCost = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int cost = nums[i - 1] * nums[k] * nums[j] + dp[i][k] + dp[k + 1][j];
                minCost = min(minCost, cost);
            }
            dp[i][j] = minCost;
        }
    }

    return dp[1][n - 1];
}

bool isPalindrome(string s, int i, int j)
{
    while (i <= j)
    {
        if (s[i++] != s[j--])
        {
            return false;
        }
    }

    return true;
}

int countPalindromeParitionRecursive(string s, int i, int j, vector<vector<int>> &dp)
{
    if (i >= j)
    {
        return 0;
    }

    if (dp[i][j] != INT_MAX)
    {
        return dp[i][j];
    }

    if (isPalindrome(s, i, j))
    {
        return dp[i][j] = 0;
    }

    int minPartitions = INT_MAX;

    for (int k = i; k < j; k++)
    {
        int partitions = countPalindromeParitionRecursive(s, i, k, dp) +
                         countPalindromeParitionRecursive(s, k + 1, j, dp) + 1;

        minPartitions = min(minPartitions, partitions);
    }

    return dp[i][j] = minPartitions;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int n = nums.size();

    vector<vector<int>> dp1(n, vector<int>(n, INT_MAX));

    int minCost = mcmRecursion(nums, 1, n - 1, dp1);
    cout << "mcm min cost " << minCost << endl;

    // string s = "abcd";
    string s;
    cin >> s;

    n = s.size();
    vector<vector<int>> dp2(n, vector<int>(n, INT_MAX));

    int minPartitions = countPalindromeParitionRecursive(s, 0, n - 1, dp2);
    cout << "min partition count " << minPartitions << endl;

    // 1, 2, 3, 4, 5
    // l,k             r
    // 1x2, 2x3, 3x4, 4x5
    //  0   l,k        r
    //  0    0   l,k   r
    //  0    0    0
}
