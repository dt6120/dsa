#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pd;

// given `items` array and `w` capacity
// returns max sum of item values keeping item weight sum under w
int knapsackRecursion(vector<pd> &items, int w, int n, vector<vector<int>> &dp)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }

    if (dp[n - 1][w - 1] != -1)
    {
        return dp[n - 1][w - 1];
    }

    int value = items[n - 1].first;
    int weight = items[n - 1].second;

    if (weight > w)
    {
        return dp[n - 1][w - 1] = knapsackRecursion(items, w, n - 1, dp);
    }

    return dp[n - 1][w - 1] = max(
               value + knapsackRecursion(items, w - weight, n - 1, dp),
               knapsackRecursion(items, w, n - 1, dp));
}

int knapsackTabulation(vector<pd> &items, int w, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));

    // initialize base condition values in dp matrix
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 0; i <= w; i++)
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
                dp[i][j] = max(
                    value + dp[i - 1][j - weight],
                    dp[i - 1][j]);
            }
        }
    }

    return dp[n][w];
}

bool subsetSum(vector<int> &nums, int sum)
{
    // create dp matrix
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    // set initial base condition values
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = false;
    }

    // follow bottom up approach
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            int value = nums[i - 1];

            if (value > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] =
                    dp[i - 1][j - value] ||
                    dp[i - 1][j];
            }
        }
    }
    // return target result from dp matrix
    return dp[n][sum];
}

bool equalSubsetSum(vector<int> &nums)
{
    int sum = 0;
    for (int num : nums)
    {
        sum += num;
    }

    if (sum % 2 != 0)
    {
        return false;
    }

    return subsetSum(nums, sum / 2);
}

int countSubsets(vector<int> &nums, int sum)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));

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
            int value = nums[i - 1];
            if (value > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j - value] + dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int minSubsetSumDifference(vector<int> &nums)
{
    // divide nums into two subsets such that difference of subset sums is minimum
    // subset sum can vary from 0 to sum of nums

    int n = nums.size();

    int sum = 0;
    for (int num : nums)
    {
        sum += num;
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }

    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = false;
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
                dp[i][j] = dp[i - 1][j - num] || dp[i - 1][j];
            }
        }
    }

    for (int i = sum / 2; i >= 0; i--)
    {
        if (dp[n][i])
        {
            return abs(sum - 2 * i);
        }
    }

    return sum;
}

int countSubsetSumDifference(vector<int> &nums, int diff)
{
    int sum = 0;
    for (int num : nums)
    {
        sum += num;
    }

    if ((sum - diff) % 2 != 0)
    {
        return 0;
    }

    int target = (sum - diff) / 2;

    return countSubsets(nums, target);
}

int main()
{
    vector<pd> items = {{1, 1}, {4, 3}, {5, 4}, {7, 5}};

    int n = items.size();
    int w = 7;

    // dp[n+1][w+1] = max profit using n items keeping weight under w
    vector<vector<int>> dp(n, vector<int>(w, -1));

    // recursive approach
    // - start from target condition
    // - go down till base condition
    // - come back up with values that form target
    // tc: o(n^2)
    // sc: o(n.w + n)
    int res = knapsackRecursion(items, w, n, dp);
    cout << "knapsack result " << res << endl;

    // bottom-up approach
    // - start from base condition
    // - go up till target condition
    res = knapsackTabulation(items, w, n);
    cout << "bottom-up result " << res << endl;

    vector<int> nums = {2, 3, 7, 8};
    bool exists = subsetSum(nums, 20);

    cout << "subset exists " << exists << endl;

    nums = {1, 5, 11, 5};
    int count = countSubsets(nums, 11);

    cout << "subset count " << count << endl;

    nums = {1, 3, 7, 4, 18};
    int minDiff = minSubsetSumDifference(nums);

    cout << "min subset sum diff " << minDiff << endl;

    int diffCount = countSubsetSumDifference(nums, 3);

    cout << "subset diff count " << diffCount << endl;
}
