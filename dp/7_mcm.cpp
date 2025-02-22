// rod cut
// burst balloon
// egg drop

#include <bits/stdc++.h>

using namespace std;

int mcm(vector<int> &nums, int i, int j, vector<vector<int>> &dp)
{
    if (i >= j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int minOps = INT_MAX;

    for (int k = i; k <= j - 1; k++)
    {
        int ops = mcm(nums, i, k, dp) +
                  mcm(nums, k + 1, j, dp) +
                  nums[i - 1] * nums[k] * nums[j];
        minOps = min(minOps, ops);
    }

    return dp[i][j] = minOps;
}

int mcm(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // recursion: i -> 0 to n-1
    //            j -> n-1 to i+1

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; i < n; j++)
        {
            int minOps = INT_MAX;

            for (int k = i; k <= j - 1; k++)
            {
                int ops = dp[i][k] + dp[k + 1][j] + nums[i - 1] * nums[k] * nums[j];
                minOps = min(minOps, ops);
            }

            dp[i][j] = minOps;
        }
    }

    return dp[1][n - 1];
}

int minRodCuttingCost(vector<int> &nums, int i, int j, vector<vector<int>> &dp)
{
    if (i > j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = INT_MAX;

    for (int k = i; k <= j; k++)
    {
        int cost = nums[j + 1] - nums[i - 1] +
                   minRodCuttingCost(nums, i, k - 1, dp) +
                   minRodCuttingCost(nums, k + 1, j, dp);
        ans = min(ans, cost);
    }

    return dp[i][j] = ans;
}

int minRodCuttingCost(int n, vector<int> &cuts)
{
    int c = cuts.size();
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());

    // recursion: i -> 1 to c
    //            j -> c -> i
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

    for (int i = c; i >= 1; i--)
    {
        for (int j = i; j <= c; j++)
        {
            int ans = INT_MAX;

            for (int k = i; k <= j; k++)
            {
                int cost = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                ans = min(ans, cost);
            }

            dp[i][j] = ans;
        }
    }

    return dp[1][c];
}

int burstBalloons(vector<int> &nums, int i, int j)
{
    if (i > j)
    {
        return 0;
    }

    int ans = INT_MIN;

    for (int k = i; k <= j; k++)
    {
        int cost = nums[i - 1] * nums[k] * nums[j + 1] +
                   burstBalloons(nums, i, k - 1) +
                   burstBalloons(nums, k + 1, j);
        ans = max(ans, cost);
    }

    return ans;
}

int burstBalloons(vector<int> &nums)
{
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    // recursion: i -> 1 to n
    //            j -> n to i
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j <= n; j++)
        {
            int ans = INT_MIN;

            for (int k = i; k <= j; k++)
            {
                int cost = nums[i - 1] * nums[k] * nums[j + 1] +
                           dp[i][k - 1] +
                           dp[k + 1][j];
                ans = max(ans, cost);
            }

            dp[i][j] = ans;
        }
    }

    return dp[1][n];
}

int main()
{
}
