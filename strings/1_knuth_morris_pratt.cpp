#include <bits/stdc++.h>

using namespace std;

vector<int> constructPrefixArray(string &pattern)
{
    int n = pattern.size();
    vector<int> pi(n, 0);

    int i = 1, len = 0;
    while (i < n)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            pi[i] = len;
            i++;
        }
        else if (len != 0)
        {
            len = pi[len - 1];
        }
        else
        {
            pi[i] = 0;
            i++;
        }
    }

    return pi;
}

vector<int> search(string &t, string &p)
{
    int m = t.size(), n = p.size();
    int i = 0, j = 0;

    vector<int> indices;
    vector<int> pi = constructPrefixArray(p);
    // pi[i] = length of the longest proper prefix of pattern[0, i]
    // which is also a suffix of pattern[0, i]
    for (int i : pi) {
        cout << i << " ";
    }
    cout << endl;

    while (i < m)
    {
        if (t[i] == p[j])
        {
            i++;
            j++;

            if (j == n)
            {
                indices.push_back(i - j);
                j = pi[j - 1];
            }
        }
        else if (j != 0)
        {
            j = pi[j - 1];
        }
        else
        {
            i++;
        }
    }

    return indices;
}

int main()
{
    string t = "aabaacaadaabaabaa", p = "uvxyz";

    vector<int> indices = search(t, p);

    for (int i : indices)
    {
        cout << i << " ";
    }
}
