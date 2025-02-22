#include <bits/stdc++.h>

using namespace std;

int knows(int a, int b)
{
    vector<vector<int>> adj = {{0, 1, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};

    return adj[a][b];
}

int findCelebrity(int n)
{
    int top = 0, down = n - 1;

    while (top < down)
    {
        if (knows(top, down))
        {
            top++;
        }
        else
        {
            down--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i != top && (knows(top, i) || !knows(i, top)))
        {
            return -1;
        }
    }

    return top;
}

int main()
{
    int n = 4;

    cout << findCelebrity(n);
}