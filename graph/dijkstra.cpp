#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pd;

void print(vector<int> &arr, bool reverse)
{
    int n = arr.size();
    if (reverse)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

void dijkstraPQ(vector<vector<int>> &adj, int src)
{
    int n = adj.size();
    vector<int> dist(n, INT_MAX);

    priority_queue<pd, vector<pd>, greater<pd>> pq;
    pq.push({0, src});
    dist[src] = 0;
    int c1 = 0;
    int c2 = 0;

    while (!pq.empty())
    {
        pd top = pq.top();
        int curDist = top.first;
        int curNode = top.second;
        pq.pop();

        c1++;

        if (curDist != dist[curNode])
        {
            continue;
        }

        c2++;

        for (int i = 0; i < adj[curNode].size(); i++)
        {
            int edgeWeight = adj[curNode][i];
            if (edgeWeight > 0)
            {
                int newDist = curDist + edgeWeight;
                if (newDist < dist[i])
                {
                    dist[i] = newDist;
                    pq.push({newDist, i});
                }
            }
        }
    }

    for (int d : dist)
    {
        cout << d << " ";
    }
    cout << endl;

    cout << "c1 " << c1 << " c2 " << c2 << endl;
}

void dijkstraSet(vector<vector<int>> &adj, int src)
{
    int n = adj.size();
    vector<int> dist(n, INT_MAX);

    set<pd> set;
    set.insert({0, src});
    dist[src] = 0;

    while (!set.empty())
    {
        pd top = *set.begin();
        int curDist = top.first;
        int curNode = top.second;
        set.erase(top);

        for (int i = 0; i < adj[curNode].size(); i++)
        {
            int edgeWeight = adj[curNode][i];
            if (edgeWeight > 0)
            {
                int newDist = curDist + edgeWeight;
                if (newDist < dist[i])
                {
                    dist[i] = newDist;
                    set.insert({newDist, i});
                }
            }
        }
    }

    for (int d : dist)
    {
        cout << d << " ";
    }
    cout << endl;
}

void dijkstraPath(vector<vector<int>> &adj, int src, int dst)
{
    int n = adj.size();
    vector<int> dist(n, INT_MAX);

    vector<int> parent(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    priority_queue<pd, vector<pd>, greater<pd>> pq;
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty())
    {
        pd top = pq.top();
        int curDist = top.first;
        int curNode = top.second;
        pq.pop();

        for (int i = 0; i < adj[curNode].size(); i++)
        {
            int edgeWeight = adj[curNode][i];
            if (edgeWeight > 0)
            {
                int newDist = curDist + edgeWeight;
                if (newDist < dist[i])
                {
                    pq.push({newDist, i});
                    dist[i] = newDist;
                    parent[i] = curNode;
                }
            }
        }
    }

    print(dist, false);
    print(parent, false);

    if (dist[dst] == INT_MAX)
    {
        cout << "No path found" << endl;
    }

    vector<int> path;
    while (parent[dst] != dst)
    {
        path.push_back(dst);
        dst = parent[dst];
    }
    path.push_back(dst);

    print(path, true);
}

int main()
{
    vector<vector<int>> adj;
    vector<int> row1 = {0, 4, 4, 0, 0, 0};
    vector<int> row2 = {4, 0, 2, 0, 0, 0};
    vector<int> row3 = {4, 2, 0, 3, 1, 6};
    vector<int> row4 = {0, 0, 3, 0, 0, 2};
    vector<int> row5 = {0, 0, 1, 0, 0, 3};
    vector<int> row6 = {0, 0, 6, 2, 3, 0};

    adj.push_back(row1);
    adj.push_back(row2);
    adj.push_back(row3);
    adj.push_back(row4);
    adj.push_back(row5);
    adj.push_back(row6);

    dijkstraPQ(adj, 0);
    // dijkstraSet(adj, 0);
    // dijkstraPath(adj, 0, 5);
}