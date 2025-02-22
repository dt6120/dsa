#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> left(n, 1), right(n, 1);

        for (int i = 0; i < n; i++)
        {
            int j = n - i - 1;
            if (i > 0 && ratings[i] > ratings[i - 1])
            {
                left[i] = left[i - 1] + 1;
            }
            if (j < n - 1 && ratings[j] > ratings[j + 1])
            {
                right[j] = right[j + 1] + 1;
            }
        }

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += max(left[i], right[i]);
        }

        return sum;
    }
};