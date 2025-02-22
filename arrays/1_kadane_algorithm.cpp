/*
53. Maximum Subarray

Given an integer array nums, find the subarray with the largest sum, and return its sum.

https://leetcode.com/problems/maximum-subarray/description/
*/

#include <bits/stdc++.h>

using namespace std;

int findMaxSumSubarray(vector<int> &nums)
{
    int n = nums.size();
    int maxSum = INT_MIN, curSum = 0;
    int start = 0, end = 0, temp = 0;

    for (int i = 0; i < n; i++)
    {
        int num = nums[i];

        curSum += num;

        if (curSum > maxSum)
        {
            maxSum = curSum;
            start = temp;
            end = i;
        }

        if (curSum <= 0)
        {
            curSum = 0;
            temp = i + 1;
        }
    }

    cout << "Range ";

    return maxSum;
}

int main()
{
}