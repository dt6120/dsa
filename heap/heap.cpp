#include <bits/stdc++.h>

using namespace std;

class MinHeap
{
private:
    vector<int> arr;

public:
    MinHeap(int x) { arr.push_back(x); }
    MinHeap(vector<int> x) { arr = x; }

    void insert(int x)
    {
        arr.push_back(x);
        int elemIndex = arr.size() - 1;
        int parentIndex = floor(static_cast<float>(arr.size()) / static_cast<float>(2)) - 1;

        print();

        while (parentIndex >= 0 && arr[parentIndex] > x)
        {
            int temp = arr[parentIndex];
            arr[parentIndex] = arr[elemIndex];
            arr[elemIndex] = temp;
            elemIndex = parentIndex;

            print();

            parentIndex = floor(static_cast<float>(parentIndex + 1) / static_cast<float>(2)) - 1;
        }
    }

    void remove(int index)
    {
        int lastElem = arr[arr.size() - 1];
        arr[index] = lastElem;
        arr.pop_back();

        int n = arr.size();

        
    }

    void print()
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            cout << i + 1 << "  ";
        }
        cout << endl;

        for (int i : arr)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main()
{
    vector<int> arr = {70, 60, 40, 45, 50, 39, 16, 10, 11};
    MinHeap *heap = new MinHeap(arr);
    heap->insert(44);
}