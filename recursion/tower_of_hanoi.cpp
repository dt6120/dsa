#include <bits/stdc++.h>

using namespace std;

typedef stack<int> si;

void toh(int n, si &s, si &d, si &h)
{
    if (n == 1)
    {
        int top = s.top();
        s.pop();
        d.push(top);
        cout << "Shifting " << top << endl;
        return;
    }

    toh(n - 1, s, h, d);
    int top = s.top();
    s.pop();
    d.push(top);
    cout << "Shifting " << top << endl;
    toh(n - 1, h, d, s);
}

void toh(int n, int s, int d, int h)
{
    if (n == 1)
    {
        cout << "Shifting 1 from " << s << " to " << d << endl;
        return;
    }

    toh(n - 1, s, h, d);
    cout << "Shifting " << n << " from " << s << " to " << d << endl;
    toh(n - 1, h, d, s);
}

int main()
{
    int n = 4;

    si s, d, h;
    for (int i = n; i > 0; i--)
    {
        s.push(i);
    }

    // toh(n, s, d, h);
    toh(n, 1, 3, 2);
}
