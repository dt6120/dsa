#include <bits/stdc++.h>

using namespace std;

// one way to implement is to store pair<int, int> in stack
// first item will be actual value
// second item will be minimum value till that index
// this gives TC: O(1) for getMin() but requires SC: O(2*n)

// another approach shown below optimizes SC to O(n) using math formula

class MinStack
{
private:
    stack<int> st;
    int minVal;

public:
    bool empty()
    {
        return st.empty();
    }

    void push(int val)
    {
        if (st.empty())
        {
            st.push(val);
            minVal = val;
        }
        else if (val > minVal)
        {
            st.push(val);
        }
        else
        {
            st.push(2 * val - minVal);
            minVal = val;
        }
    }

    int top()
    {
        if (st.top() > minVal)
        {
            return st.top();
        }
        else
        {
            return minVal;
        }
    }

    void pop()
    {
        int top = st.top();
        st.pop();

        if (top < minVal)
        {
            minVal = 2 * minVal - top;
        }
    }

    int getMin()
    {
        return minVal;
    }
};

int main()
{
    MinStack *stack = new MinStack();
    stack->push(10);
    stack->push(12);
    stack->push(8);
    stack->push(6);
    cout << stack->getMin() << endl;
    stack->pop();
    cout << stack->getMin() << endl;
    stack->pop();
    cout << stack->getMin() << endl;
    stack->pop();
    cout << stack->getMin() << endl;
}
