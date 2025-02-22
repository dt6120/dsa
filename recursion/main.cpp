#include <bits/stdc++.h>

using namespace std;

void balancedParenthesis(vector<string> &result, string &curS, int openLeft, int closeLeft)
{
    if (openLeft == 0 && closeLeft == 0)
    {
        return;
    }

    if (openLeft == closeLeft)
    {
        curS.push_back('(');
        balancedParenthesis(result, curS, openLeft - 1, closeLeft);
        curS.pop_back();
    }
    else if (openLeft < closeLeft)
    {
        if (openLeft > 0)
        {
            curS.push_back('(');
            balancedParenthesis(result, curS, openLeft - 1, closeLeft);
            curS.pop_back();
        }

        curS.push_back(')');
        balancedParenthesis(result, curS, openLeft, closeLeft - 1);
        curS.pop_back();
    }
}

int main()
{
    int n = 3;
    vector<string> result;
    string curS = "";

    balancedParenthesis(result, curS, n, n);

    for (string s : result)
    {
        cout << s << endl;
    }
}
