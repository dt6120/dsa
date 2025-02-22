#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int find(vector<int> &nums, int i, int j, vector<vector<int>> &dp)
    {
        int n = nums.size();
        if (i == n)
        {
            return 0;
        }

        if (dp[i][j + 1] != -1)
        {
            return dp[i][j + 1];
        }

        if (j == -1 || nums[i] > nums[j])
        {
            return dp[i][j + 1] = max(
                       1 + find(nums, i + 1, i, dp),
                       find(nums, i + 1, j, dp));
        }

        return dp[i][j + 1] = find(nums, i + 1, j, dp);
    }

    int lisTabulation(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i - 1; j >= -1; j--)
            {
                if (j == -1 || nums[i] > nums[j])
                {
                    dp[i][j + 1] = max(
                        1 + dp[i + 1][i + 1],
                        dp[i + 1][j + 1]);
                }
                else
                {
                    dp[i][j + 1] = dp[i + 1][j + 1];
                }
            }
        }

        return dp[0][0];
    }

    int printLisTabulation(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> parent(n, 0);

        int index = 0;

        for (int i = 1; i < n; i++)
        {
            parent[i] = i;
            int maxSize = INT_MIN;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j] && dp[j] > maxSize)
                {
                    maxSize = dp[j];
                    parent[i] = j;
                }
            }
            dp[i] = maxSize == INT_MIN ? dp[i] : dp[i] + maxSize;

            if (dp[i] > dp[index])
            {
                index = i;
            }
        }

        while (parent[index] != index)
        {
            cout << nums[index] << " ";
            index = parent[index];
        }
        cout << nums[index] << endl;

        return dp[index];
    }

    int lisBinarySearch(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> lis;

        for (int i = 0; i < n; i++)
        {
            if (lis.size() == 0 || lis.back() < nums[i])
            {
                lis.push_back(nums[i]);
            }
            else
            {
                auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
                *it = nums[i];
            }
        }

        return lis.size();
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return find(nums, 0, -1, dp);
    }
};