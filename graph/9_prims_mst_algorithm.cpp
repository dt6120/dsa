#include <bits/stdc++.h>

using namespace std;

int primsMstAlgorithm(vector<vector<pair<int, int>>> &adj, int src)
{
    int n = adj.size(), sum = 0;
    vector<int> vis(n, 0);
    vector<vector<int>> mst;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    // wt, node, parent
    pq.push({0, src, -1});

    while (!pq.empty())
    {
        auto [wt, node, parent] = pq.top();
        pq.pop();

        if (vis[node])
        {
            continue;
        }

        if (parent != -1)
        {
            mst.push_back({parent, node});
            sum += wt;
        }

        vis[node] = 1;

        for (auto d : adj[node])
        {
            if (!vis[d.first])
            {
                pq.push({d.second, d.first, node});
            }
        }
    }

    return sum;
}

int main() {}
