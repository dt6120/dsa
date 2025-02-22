#include <bits/stdc++.h>

using namespace std;

vector<int> nge(vector<int> &nums)
{
    // monotonic stack to store elements in decreasing order
    stack<int> st;

    int n = nums.size();
    vector<int> nge(n);

    for (int i = n - 1; i >= 0; i--)
    {
        // this loop will run cumulatively for max `n` times
        while (!st.empty() && st.top() <= nums[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            nge[i] = -1;
        }
        else
        {
            nge[i] = st.top();
        }

        st.push(nums[i]);
    }

    // TC: O(2*n) as for loop runs `n` times and while loop runs max `n` times overall

    return nge;
}

vector<int> nge2(vector<int> &nums)
{
    stack<int> st;

    int n = nums.size();
    vector<int> nge(n);

    for (int i = 2 * n - 1; i >= 0; i++)
    {
        int j = i % n;
        while (!st.empty() && nums[j] >= st.top())
        {
            st.pop();
        }

        if (i < n)
        {
            nge[i] = st.empty() ? -1 : st.top();
        }

        st.push(nums[j]);
    }

    return nge;
}

vector<int> pse(vector<int> &nums)
{
    stack<int> st;

    int n = nums.size();
    vector<int> pse(n);

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[i] <= st.top())
        {
            st.pop();
        }

        if (st.empty())
        {
            pse[i] = -1;
        }
        else
        {
            pse[i] = st.top();
        }

        st.push(nums[i]);
    }

    return pse;
}

int main()
{
}
