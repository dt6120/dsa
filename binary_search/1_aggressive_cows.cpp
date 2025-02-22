#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pd;

bool placeCows(vector<int> &stalls, int cows, int minDist)
{
    int n = stalls.size(), l = 0, r = 1;
    cows--;

    while (r < n)
    {
        int dist = stalls[r] - stalls[l];
        if (dist >= minDist)
        {
            l = r;
            cows--;

            if (cows == 0)
            {
                break;
            }
        }
        r++;
    }

    return cows == 0;
}

int main()
{
    vector<int> stalls = {1, 2, 4, 8, 9};
    int cows = 5, n = stalls.size();

    sort(stalls.begin(), stalls.end());

    int l = 1, r = stalls[n - 1] - stalls[0];
    int maxMinDist = INT_MIN;

    while (l <= r)
    {
        int m = l + (r - l) / 2;
        bool possible = placeCows(stalls, cows, m);
        if (possible)
        {
            maxMinDist = max(maxMinDist, m);
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    maxMinDist = maxMinDist == INT_MIN ? 0 : maxMinDist;

    cout << maxMinDist << endl;
}
