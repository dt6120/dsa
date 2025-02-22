#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e9 + 7;

// returns number of unique paths to reach (i, j) from (0, 0)
int uniquePathRecursion(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 || j == 0)
    {
        return 1;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    return dp[i][j] = uniquePathRecursion(i - 1, j, dp) % MOD + uniquePathRecursion(i, j - 1, dp) % MOD;
}

// (m, n) is grid size
int uniquePathTabulation(int m, int n)
{
    // vector<vector<int>> dp(m, vector<int>(n));
    vector<int> prevDp(n, 1);

    for (int i = 1; i < m; i++)
    {
        vector<int> curDp(n);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0)
            {
                curDp[j] = 1;
            }
            else
            {
                curDp[j] = prevDp[j] % MOD + curDp[j - 1] % MOD;
            }
        }
        prevDp = curDp;
    }

    return prevDp[n - 1];
}

int uniqueObstaclePathRecursion(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
{
    if (grid[i][j] == -1)
    {
        return 0;
    }
    if (i == 0 || j == 0)
    {
        return 1;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    return dp[i][j] = uniqueObstaclePathRecursion(grid, i - 1, j, dp) % MOD +
                      uniqueObstaclePathRecursion(grid, i, j - 1, dp) % MOD;
}

int uniqueObstaclePathTabulation(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    vector<int> dp(n, 1);

    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n);
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == -1)
            {
                temp[j] = 0;
            }
            else if (i == 0 || j == 0)
            {
                temp[j] = 1;
            }
            else
            {
                temp[j] = temp[j - 1] + dp[j];
            }
        }
        dp = temp;
    }

    return dp[n - 1];
}

// fixed start point to fixed end point
int minPathSumRecursion(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
    {
        return grid[0][0];
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int leftCost = i == 0 ? INT_MAX : minPathSumRecursion(grid, i - 1, j, dp);
    int topCost = j == 0 ? INT_MAX : minPathSumRecursion(grid, i, j - 1, dp);

    return dp[i][j] = grid[i][j] + min(leftCost, topCost);
}

// fixed start point to fixed end point
int minPathSumTabulation(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    vector<int> dp(n);

    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                temp[j] = grid[i][j];
            }
            else if (i == 0)
            {
                temp[j] = grid[i][j] + temp[j - 1];
            }
            else if (j == 0)
            {
                temp[j] = grid[i][j] + dp[j];
            }
            else
            {
                temp[j] = grid[i][j] + min(temp[j - 1], dp[j]);
            }
        }
        dp = temp;
    }

    return dp[n - 1];
}

// fixed start point to variable end point
// returns min path sum from (i, j) to last row of pyramid
int minPyramidPathSumRecursion(vector<vector<int>> &pyramid, int i, int j, vector<vector<int>> &dp)
{
    if (i == pyramid.size() - 1)
    {
        return pyramid[i][j];
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    return dp[i][j] = pyramid[i][j] + min(minPyramidPathSumRecursion(pyramid, i + 1, j, dp),
                                          minPyramidPathSumRecursion(pyramid, i + 1, j + 1, dp));
}

// fixed start point to variable end point
int minPyramidPathSumTabulation(vector<vector<int>> &pyramid)
{
    int n = pyramid.size();

    // dp[i]: min path sum from dp row to last row of pyramid
    vector<int> dp = pyramid[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> temp(pyramid[i].size());
        for (int j = 0; j < pyramid[i].size(); j++)
        {
            temp[j] = pyramid[i][j] + min(dp[j], dp[j + 1]);
        }
        dp = temp;
    }

    return dp[0];
}

// variable start point to variable end point
int minPathSumTabulation2(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<int> dp = grid[m - 1];

    for (int i = m - 2; i >= 0; i--)
    {
        vector<int> temp(n);
        for (int j = 0; j < n; j++)
        {
            int leftCost = j == 0 ? INT_MAX : dp[j - 1];
            int rightCost = j == n - 1 ? INT_MAX : dp[j + 1];
            temp[j] = grid[i][j] + min(dp[j], min(leftCost, rightCost));
        }
        dp = temp;
    }

    int minSum = INT_MAX;
    for (int sum : dp)
    {
        minSum = min(minSum, sum);
    }

    return minSum;
}

// 3-D DP to calculate all possible combinations of both together
// returns max path sum starting from (i, j, k) to reach last row
int cherryPickupRecursion(vector<vector<int>> &grid, int i, int j, int k, vector<vector<vector<int>>> &dp)
{
    int m = grid.size(), n = grid[0].size();

    if (i == m - 1)
    {
        return j == k ? grid[i][j] : grid[i][j] + grid[i][k];
    }

    if (dp[i][j][k] != -1)
    {
        return dp[i][j][k];
    }

    int maxSum = INT_MIN;
    vector<int> path = {-1, 0, 1};

    for (int p1 : path)
    {
        for (int p2 : path)
        {
            if (j + p1 < 0 || j + p1 >= n || k + p2 < 0 || k + p2 >= n)
            {
                continue;
            }

            maxSum = max(maxSum, cherryPickupRecursion(grid, i + 1, j + p1, k + p2, dp));
        }
    }

    return dp[i][j][k] = (j == k ? grid[i][j] : grid[i][j] + grid[i][k]) + maxSum;
}

int cherryPickupTabulation(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(n));

    vector<int> path = {-1, 0, 1};

    // base condition
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            dp[j][k] = j == k ? grid[m - 1][j] : grid[m - 1][j] + grid[m - 1][k];
        }
    }

    for (int i = m - 2; i >= 0; i--)
    {
        vector<vector<int>> temp(n, vector<int>(n));
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                int maxSum = INT_MIN;
                for (int p1 : path)
                {
                    for (int p2 : path)
                    {
                        int dj = j + p1, dk = k + p2;
                        if (dj < 0 || dj >= n || dk < 0 || dk >= n)
                        {
                            continue;
                        }
                        maxSum = max(maxSum, dp[dj][dk]);
                    }
                }
                temp[j][k] = (j == k ? grid[i][j] : grid[i][j] + grid[i][k]) + maxSum;
            }
        }
        dp = temp;
    }

    return dp[0][n - 1];
}

// recursion: go from `end` condition to `base` condition
// tabulation: go from `base` condition to `end` condition

// case 1: fixed start to fixed end
// case 2: fixed start to variable end
// case 3: variable start to variable end
int main()
{
    int m = 3, n = 3;
    vector<vector<int>> dp1(m, vector<int>(n, -1));

    cout << uniquePathRecursion(m - 1, n - 1, dp1) << endl;
    cout << uniquePathTabulation(m, n) << endl;

    vector<vector<int>> grid1 = {{0, 0, 0}, {0, -1, 0}, {0, 0, 0}};
    vector<vector<int>> dp2(grid1.size(), vector<int>(grid1[0].size(), -1));

    cout << uniqueObstaclePathRecursion(grid1, grid1.size() - 1, grid1[0].size() - 1, dp2) << endl;
    cout << uniqueObstaclePathTabulation(grid1) << endl;

    vector<vector<int>> grid2 = {{5, 9, 6}, {11, 5, 2}};
    vector<vector<int>> dp3(grid2.size(), vector<int>(grid2[0].size(), -1));

    cout << minPathSumRecursion(grid2, grid2.size() - 1, grid2[0].size() - 1, dp3) << endl;
    cout << minPathSumTabulation(grid2) << endl;

    vector<vector<int>> grid3 = {{1}, {2, 3}, {3, 6, 7}, {8, 9, 6, 1}};
    vector<vector<int>> dp4(grid3.size(), vector<int>(grid3.size(), -1));

    cout << minPyramidPathSumRecursion(grid3, 0, 0, dp4) << endl;
    cout << minPyramidPathSumTabulation(grid3) << endl;

    vector<vector<int>> grid4 = {{1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};

    cout << minPathSumTabulation2(grid4) << endl;

    vector<vector<int>> grid5 = {{1, 0, 0, 0, 0, 0, 1}, {2, 0, 0, 0, 0, 3, 0}, {2, 0, 9, 0, 0, 0, 0}, {0, 3, 0, 5, 4, 0, 0}, {1, 0, 2, 3, 0, 0, 6}};
    vector<vector<vector<int>>> dp5(grid5.size(), vector<vector<int>>(grid5[0].size(), vector<int>(grid5[0].size(), -1)));

    cout << cherryPickupRecursion(grid5, 0, 0, grid5[0].size() - 1, dp5);
    cout << cherryPickupTabulation(grid5) << endl;
}