#include <bits/stdc++.h>
#include <vector>

using namespace std;

int maxSubStrBrute(vector<int> &arr, int k)
{
    int res = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            if (sum <= k)
            {
                res = max(res, j - i + 1);
            }
            else
            {
                break;
            }
        }
    }

    return res;
}

int maxSubStrSliding(vector<int> &arr, int k)
{
    int res = 0;

    int l = 0, r = 0;

    int sum = 0;
    while (r < arr.size())
    {
        sum += arr[r];
        while (sum > k)
        {
            sum -= arr[l++];
        }
        res = max(res, r - l + 1);
        r++;
    }

    return res;
}

int maxSubStrOptimized(vector<int> &arr, int k)
{
    int res = 0;

    int l = 0, r = 0;

    int sum = 0;
    while (r < arr.size())
    {
        sum += arr[r];
        if (sum > k)
        {
            sum -= arr[l++];
        }

        res = max(res, r - l + 1);
        r++;
    }

    return res;
}

int main()
{
    vector<int> arr = vector<int>{2, 5, 1, 7, 10};

    int res = maxSubStrOptimized(arr, 14);
    cout << res;
}