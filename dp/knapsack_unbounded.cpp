#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pd;

int knapsackRecursion(vector<pd> &items, int w, int n, vector<vector<int>> &dp)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }

    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }

    int value = items[n - 1].first;
    int weight = items[n - 1].second;

    if (weight > w)
    {
        return dp[n][w] = knapsackRecursion(items, n - 1, w, dp);
    }

    return dp[n][w] = max(
               value + knapsackRecursion(items, w - value, n, dp),
               knapsackRecursion(items, w, n - 1, dp));
}

int knapsackTabulation(vector<pd> items, int w, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= w; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            int value = items[i - 1].first;
            int weight = items[i - 1].second;

            if (weight > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - weight]);
            }
        }
    }

    return dp[n][w];
}

int countSubsetSum(vector<int> &nums, int sum)
{
    int n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            int num = nums[i - 1];

            if (num > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - num];
            }
        }
    }

    return dp[n][sum];
}

int minSizeSubsetSum(vector<int> &nums, int sum)
{
    int n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, INT_MAX));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = INT_MAX;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            int num = nums[i - 1];

            if (num > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = min(
                    dp[i - 1][j],
                    1 + dp[i][j - num]);
            }
        }
    }

    return dp[n][sum];
}

int main()
{
    vector<pd> items = {};

    int n = items.size();
    int w = 10;

    // dp[size of nums][weight limit] = max item value sum keeping weight sum under limit
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));

    int res = knapsackRecursion(items, w, n, dp);

    vector<int> nums = {1, 2, 3};
    int subsetCount = countSubsetSum(nums, 5);
    cout << "subset count " << subsetCount << endl;

    int minSubsetSize = minSizeSubsetSum(nums, 5);
    cout << "min size subset " << minSubsetSize << endl;
}
