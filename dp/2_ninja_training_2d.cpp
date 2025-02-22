#include <bits/stdc++.h>

using namespace std;

// returns max points from 0 to `day` by doing `task` on `day`
int ninjaTrainingRecursion(vector<vector<int>> &points, int day, int task, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        return points[day][task];
    }

    if (dp[day][task] != -1)
    {
        return dp[day][task];
    }

    return dp[day][task] = points[day][task] + max(
                                                   ninjaTrainingRecursion(points, day - 1, (task + 1) % 3, dp),
                                                   ninjaTrainingRecursion(points, day - 1, (task + 2) % 3, dp));
}

int ninjaTrainingTabulation(vector<vector<int>> &points)
{
    int n = points.size();

    // prevDp[j]: max points on previous day doing task `j`
    vector<int> prevDp = points[0];

    for (int i = 2; i <= n; i++)
    {
        vector<int> curDp(3);
        for (int j = 0; j < 3; j++)
        {
            // curDp[j]: max points on current day doing task `j`
            curDp[j] = points[i - 1][j] + max(
                                              prevDp[(j + 1) % 3],
                                              prevDp[(j + 2) % 3]);
        }
        prevDp = curDp;
    }

    return max(prevDp[0], max(prevDp[1], prevDp[2]));
}

int main()
{
    vector<vector<int>> points = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    int n = points.size();

    vector<vector<int>> dp(n, vector<int>(3, -1));

    int recRes = max(ninjaTrainingRecursion(points, n - 1, 0, dp), max(ninjaTrainingRecursion(points, n - 1, 1, dp), ninjaTrainingRecursion(points, n - 1, 2, dp)));

    cout << recRes << endl;

    cout << ninjaTrainingTabulation(points) << endl;
}
