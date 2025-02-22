/*
1838. Frequency of the Most Frequent Element

The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.

https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findFreq(vector<int> &nums, int i, int k)
    {
        // nums is sorted
        // for nums[i], use k to increment smaller elements
        int num = nums[i], freq = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            int diff = num - nums[j];
            if (k >= diff)
            {
                k -= diff;
                freq++;
            }
            else
            {
                break;
            }
        }

        return freq;
    }

    int maxFrequency(vector<int> &nums, int k)
    {
        int freq = 1, n = nums.size(), prefixSum = 0;
        sort(nums.begin(), nums.end());
        // no need to check further if array size is less than current max freq found
        // for (int i = n - 1; i >= freq; i--) {
        //     freq = max(freq, findFreq(nums, i, k));
        // }
        // return freq;

        int j = 0;
        for (int i = 1; i < n; i++)
        {
            prefixSum += nums[i - 1];
            while (j < i && (i - j) * nums[i] - prefixSum > k)
            {
                prefixSum -= nums[j];
                j++;
            }

            if (j < i)
            {
                freq = max(freq, i - j + 1);
            }
        }

        return freq;
    }
};