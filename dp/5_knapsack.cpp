#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pd;

int knapsack(vector<pd>& items, int wt, int n, vector<vector<int>>& dp) {
    if (n == 0 || wt == 0) {
        return 0;
    }

    if (dp[n][wt] != -1) {
        return dp[n][wt];
    }

    int value = items[n-1].first;
    int weight = items[n-1].second;

    if (weight > wt) {
        return dp[n][wt] = knapsack(items, wt, n-1, dp);
    }

    return dp[n][wt] = max(knapsack(items, wt, n-1, dp), weight + knapsack(items, wt-weight, n-1, dp));
}

int knapsack(vector<pd> &items, int wt)
{
    int n = items.size();

    vector<int> dp(wt + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        int value = items[i - 1].first;
        int weight = items[i - 1].second;

        vector<int> temp(wt+1);
        for (int j = 1; j <= wt; j++)
        {
            if (weight > j)
            {
                temp[j] = dp[j];
            }
            else
            {
                temp[j] = max(dp[j], dp[j - weight]);
            }
        }
        dp = temp;
    }

    return dp[wt];
}

int minCoinsUnlimited(vector<int>& coins, int sum) {
    int n = coins.size();

    vector<int> dp(sum+1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        vector<int> temp(sum+1);
        temp[0] = 0;
        for (int j = 1; j <= sum; j++) {
            int value = coins[i-1];

            if (value > j) {
                temp[j] = dp[j];
            } else {
                temp[j] = min(1 + temp[j-value], dp[j]);
            }
        }
        dp = temp;
    }

    return dp[sum];
}

int main() {}
