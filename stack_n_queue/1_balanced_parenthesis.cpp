#include <bits/stdc++.h>

using namespace std;

/*
    check if string passed has balanced parenthesis
    i.e. order of opening and closing brackets is maintained
*/
bool hasBalancedParenthesis(string s)
{
    stack<char> stack;

    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            stack.push(c);
            continue;
        }

        if (stack.empty())
        {
            return false;
        }

        if (
            (c == ')' && stack.top() == '(') ||
            (c == '}' && stack.top() == '{') ||
            (c == ']' && stack.top() == '['))
        {
            stack.pop();
        } else {
            return false;
        }
    }

    return stack.empty();
}

int main()
{
    string s;
    cin >> s;

    cout << hasBalancedParenthesis(s) << endl;
}