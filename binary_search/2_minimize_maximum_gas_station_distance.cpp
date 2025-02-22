#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool possible(vector<int> &nums, int k, double m)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            int diff = nums[i + 1] - nums[i];
            if (diff <= m)
            {
                continue;
            }

            k -= diff / (m + 1);
            if (k < 0)
            {
                return false;
            }
        }
        return k == 0;
    }

    double minmaxGasDist(vector<int> &stations, int k)
    {
        sort(stations.begin(), stations.end());
        double l = 0, h = 1e9, ans = -1;
        while (l <= h)
        {
            double m = l + (h - l) / 2;
            if (possible(stations, k, m))
            {
                cout << "Max dist of " << m << " possible" << endl;
                h = m - 0.1;
                if (abs(ans - m) <= pow(10, -6))
                {
                    ans = m;
                    break;
                }
                ans = m;
            }
            else
            {
                cout << "Max dist of " << m << " not possible" << endl;
                l = m + 0.1;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> stations = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 9;
    // vector<int> stations = {3, 6, 12, 19, 33, 44, 67, 72, 89, 95};
    // int k = 2;

    Solution *sol = new Solution();
    cout << sol->minmaxGasDist(stations, k) << endl;
}
