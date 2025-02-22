#include <bits/stdc++.h>

using namespace std;

int trappingRainwater(vector<int> &buildings)
{
    int n = buildings.size();
    vector<int> maxLeft(n);
    vector<int> maxRight(n);

    for (int i = 0; i < n; i++)
    {
        int j = n - i - 1;

        maxLeft[i] = i == 0 ? 0 : max(maxLeft[i - 1], buildings[i - 1]);
        maxRight[j] = j == n - 1 ? 0 : max(maxRight[j + 1], buildings[j + 1]);
    }

    int volume = 0;
    for (int i = 0; i < n; i++)
    {
        int maxHeight = min(maxLeft[i], maxRight[i]);
        volume += maxHeight > buildings[i] ? maxHeight - buildings[i] : 0;
    }

    return volume;
}

int trappingRainwater2(vector<int>& heights) {
    int n = heights.size();
    int l = 0, r = n-1, ml= 0, mr = 0, volume = 0;

    while (l < r) {
        int hl = heights[l], hr = heights[r];
        if (hl <= hr) {
            volume += ml > hl ? ml-hl : 0;
            ml = max(ml, hl);
            l++;
        } else {
            volume += mr > hr ? mr - hr : 0;
            mr = max(mr, hr);
            r--;
        }
    }

    return volume;
}

int main()
{
    vector<int> buildings = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout << trappingRainwater2(buildings) << endl;
}
