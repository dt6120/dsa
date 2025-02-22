#include <bits/stdc++.h>

using namespace std;

bool subsetSum(vector<int> &nums, int sum, int n)
{
    if (sum == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return false;
    }

    if (nums[n - 1] > sum)
    {
        return subsetSum(nums, sum, n - 1);
    }

    return subsetSum(nums, sum, n - 1) || subsetSum(nums, sum - nums[n - 1], n - 1);
}

bool subsetSum(vector<int> &nums, int sum)
{
    int n = nums.size();
    // dp[n][sum]: using n elements of array, does any subset exist with sum
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        vector<int> temp(sum + 1, 1);
        for (int j = 1; j <= sum; j++)
        {
            int num = nums[i - 1];

            if (num > j)
            {
                temp[j] = dp[j];
            }
            else
            {
                temp[j] = dp[j - num] || dp[j];
            }
        }

        dp = temp;
    }

    return dp[sum];
}

int subsetSumCount(vector<int> &nums, int sum)
{
    int n = nums.size();
    // dp[n][sum]: using n elements of array, number of subarrays with sum
    vector<int> dp(sum + 1, 0);

    for (int i = 0; i <= sum; i++)
    {
        int num = nums[0];
        if (i == 0 && num == 0)
        {
            dp[i] = 2;
        }
        else if (i == 0 || i == num)
        {
            dp[i] = 1;
        }
        else
        {
            dp[i] = 0;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        vector<int> temp(sum + 1, 1);
        for (int j = 0; j <= sum; j++)
        {
            int num = nums[i - 1];

            if (i == 1)
            {
                if (j == 0 && num == 0)
                {
                    temp[j] = 2;
                }
                else if (j == 0 || j == num)
                {
                    temp[j] = 1;
                }
                else
                {
                    temp[j] = 0;
                }
                continue;
            }

            if (num > j)
            {
                temp[j] = dp[j];
            }
            else
            {
                temp[j] = dp[j - num] + dp[j];
            }
        }

        dp = temp;
    }

    return dp[sum];
}

int minDiffPartition(vector<int> &nums)
{
    int sum = 0;
    for (int num : nums)
    {
        sum += num;
    }

    int n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
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
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - num];
            }
        }
    }

    for (int i = sum / 2; i >= 0; i--)
    {
        if (dp[n][i])
        {
            return sum - 2 * i;
        }
    }

    return sum;
}

int main()
{
    // vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> nums = {0, 0, 1};

    cout << subsetSum(nums, 10, nums.size()) << endl;
    cout << subsetSum(nums, 16) << endl;
    cout << subsetSumCount(nums, 0) << endl;

    cout << minDiffPartition(nums) << endl;
}
