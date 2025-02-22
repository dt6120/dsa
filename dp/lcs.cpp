#include <bits/stdc++.h>

using namespace std;

int countLcSubsequenceRecursion(string x, string y, int s1, int s2, vector<vector<int>> &dp)
{
    if (s1 == 0 || s2 == 0)
    {
        return 0;
    }

    if (dp[s1 - 1][s2 - 1] != -1)
    {
        return dp[s1 - 1][s2 - 1];
    }

    if (x[s1 - 1] == y[s2 - 1])
    {
        return dp[s1 - 1][s2 - 1] = 1 + countLcSubsequenceRecursion(x, y, s1 - 1, s2 - 1, dp);
    }

    return dp[s1 - 1][s2 - 1] = max(countLcSubsequenceRecursion(x, y, s1 - 1, s2, dp), countLcSubsequenceRecursion(x, y, s1, s2 - 1, dp));
}

int countLcSubsequenceTabulation(string x, string y)
{
    int s1 = x.size(), s2 = y.size();
    vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, -1));

    for (int i = 0; i <= s1; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= s2; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= s1; i++)
    {
        for (int j = 1; j <= s2; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[s1][s2];
}

string lcSubsequenceRecursion(string x, string y)
{
    int s1 = x.size(), s2 = y.size();
    vector<vector<int>> dp(s1, vector<int>(s2, -1));
    int size = countLcSubsequenceRecursion(x, y, s1, s2, dp);

    string lcs;

    while (s1 > 0 && s2 > 0)
    {
        if (x[s1 - 1] == y[s2 - 1])
        {
            lcs.push_back(x[s1 - 1]);
            s1--;
            s2--;
        }
        else if (s1 > 1 && s2 > 1)
        {
            if (dp[s1 - 2][s2 - 1] > dp[s1 - 1][s2 - 2])
            {
                s1--;
            }
            else
            {
                s2--;
            }
        }
        else
        {
            break;
        }
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}

string lcSubsequenceTabulation(string x, string y)
{
    int s1 = x.size(), s2 = y.size();
    // vector<vector<string>> dp(s1 + 1, vector<string>(s2 + 1, ""));
    vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, -1));

    for (int i = 0; i <= s1; i++)
    {
        // dp[i][0] = "";
        dp[i][0] = 0;
    }

    for (int i = 1; i <= s2; i++)
    {
        // dp[0][i] = "";
        dp[0][i] = 0;
    }

    for (int i = 1; i <= s1; i++)
    {
        for (int j = 1; j <= s2; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                // dp[i][j] = dp[i - 1][j - 1] + x[i - 1];
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                // dp[i][j] = dp[i - 1][j].size() > dp[i][j - 1].size() ? dp[i - 1][j] : dp[i][j - 1];
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string lcs;

    while (s1 > 0 && s2 > 0)
    {
        if (x[s1 - 1] == y[s2 - 1])
        {
            lcs.push_back(x[s1 - 1]);
            s1--;
            s2--;
        }
        else if (dp[s1 - 1][s2] > dp[s1][s2 - 1])
        {
            s1--;
        }
        else
        {
            s2--;
        }
    }

    // return dp[s1][s2];
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int countLcSubstringRecursive(string x, string y, int s1, int s2, vector<vector<int>> &dp)
{
    if (s1 == 0 || s2 == 0)
    {
        return 0;
    }

    if (dp[s1 - 1][s2 - 1] != -1)
    {
        return dp[s1 - 1][s2 - 1];
    }

    for (int i = s1 - 1; i >= 0; i--)
    {
        for (int j = s2 - 1; j >= 0; j--)
        {
            if (x[i] == y[j])
            {
                dp[i][j] = 1 + countLcSubstringRecursive(x, y, i, j, dp);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return dp[s1 - 1][s2 - 1];
}

int countLcSubstringTabulation(string x, string y)
{
    int s1 = x.size(), s2 = y.size();
    vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, -1));

    for (int i = 0; i <= s1; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= s2; i++)
    {
        dp[0][i] = 0;
    }

    int maxSize = 0;

    for (int i = 1; i <= s1; i++)
    {
        for (int j = 1; j <= s2; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                maxSize = max(maxSize, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return maxSize;
}

string lcSubstringTabulation(string x, string y)
{
    int s1 = x.size(), s2 = y.size();
    vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, -1));

    for (int i = 0; i <= s1; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= s2; i++)
    {
        dp[0][i] = 0;
    }

    int maxSize = 0, end = 0;

    for (int i = 1; i <= s1; i++)
    {
        for (int j = 1; j <= s2; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if (dp[i][j] > maxSize)
                {
                    maxSize = dp[i][j];
                    end = i;
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return x.substr(end - maxSize, maxSize);
}

int sizeShortestCommonSuperSequence(string x, string y)
{
    int lcsSize = countLcSubsequenceTabulation(x, y);
    return x.size() + y.size() - lcsSize;
}

string shortestCommonSuperSequence(string x, string y)
{
    int s1 = x.size(), s2 = y.size();
    vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, -1));

    for (int i = 0; i <= s1; i++)
    {
        for (int j = 0; j <= s2; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= s1; i++)
    {
        for (int j = 1; j <= s2; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(
                    dp[i - 1][j],
                    dp[i][j - 1]);
            }
        }
    }

    string scs;

    while (s1 > 0 && s2 > 0)
    {
        if (x[s1 - 1] == y[s2 - 1])
        {
            scs.push_back(x[s1 - 1]);
            s1--;
            s2--;
        }
        else if (dp[s1 - 1][s2] > dp[s1][s2 - 1])
        {
            scs.push_back(x[s1 - 1]);
            s1--;
        }
        else
        {
            scs.push_back(y[s2 - 1]);
            s2--;
        }
    }

    while (s1 > 0)
    {
        scs += x[s1--];
    }
    while (s2 > 0)
    {
        scs += x[s2--];
    }

    reverse(scs.begin(), scs.end());
    return scs;
}

int sizeLongestRepeatingSubsequence(string x)
{
    string y = x;
    int s1 = x.size(), s2 = y.size();
    vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, -1));

    for (int i = 0; i <= s1; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= s2; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= s1; i++)
    {
        for (int j = 1; j <= s2; j++)
        {
            if (x[i - 1] == y[j - 1] && i != j)
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

int main()
{
    // string x = "abcdgkr";
    // string y = "abedfh";
    string x, y;
    cin >> x >> y;
    int s1 = x.size(), s2 = y.size();

    vector<vector<int>> dp1(s1, vector<int>(s2, -1));
    int size = countLcSubsequenceRecursion(x, y, s1, s2, dp1);
    cout << "lcs recursion size " << size << endl;

    size = countLcSubsequenceTabulation(x, y);
    cout << "lcs tabulation size " << size << endl;

    string lcs = lcSubsequenceRecursion(x, y);
    cout << "lc subsequence recursion " << lcs << endl;

    lcs = lcSubsequenceTabulation(x, y);
    cout << "lc subsequence tabulation " << lcs << endl;

    size = countLcSubstringTabulation(x, y);
    cout << "lc substring tabulation size " << size << endl;

    vector<vector<int>> dp2(s1, vector<int>(s2, -1));
    size = countLcSubstringRecursive(x, y, s1, s2, dp2);

    int maxSize = 0;
    for (int i = 0; i < s1; i++)
    {
        for (int j = 0; j < s2; j++)
        {
            maxSize = max(maxSize, dp2[i][j]);
        }
    }
    cout << "lc substring recursion size " << maxSize << endl;

    lcs = lcSubstringTabulation(x, y);
    cout << "lc substring tabulation " << lcs << endl;

    size = sizeShortestCommonSuperSequence(x, y);
    cout << "shortest common super sequence size " << size << endl;

    string scs = shortestCommonSuperSequence(x, y);
    cout << "shortest common super sequence " << scs << endl;
}
