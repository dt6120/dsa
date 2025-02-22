#include <bits/stdc++.h>

using namespace std;

// finds shortest path from src to dst in a negative weighted cycle
// also helps to detect negative cycles

int bellmanFord(vector<vector<int>> &edges, int n)
{
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;

    // relax all edges sequentially n-1 times
    // reduce if dist[u] + d < dist[v]
    for (int i = 0; i < n - 1; i++)
    {
        for (auto e : edges)
        {
            int src = e[0], dst = e[1], wt = e[2];
            if (dist[src] + wt < dist[dst])
            {
                dist[dst] = dist[src] + wt;
            }
        }
    }

    // if dist reduces on nth time, negative cycle detected
    for (auto e : edges)
    {
        int src = e[0], dst = e[1], wt = e[2];
        if (dist[src] + wt < dist[dst])
        {
            return -1;
        }
    }

    return dist[n - 1];
}

int main() {}