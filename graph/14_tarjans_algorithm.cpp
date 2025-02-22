#include <bits/stdc++.h>

using namespace std;

class TarjansAlgorithm
{
private:
    int timer = 1;

    void dfs(
        vector<vector<int>> &adj,
        int src,
        int parent,
        vector<int> &vis,
        vector<int> &tin,
        vector<int> &low,
        vector<vector<int>> &bridges)
    {
        vis[src] = 1;
        tin[src] = timer;
        low[src] = timer;
        timer++;

        for (auto dst : adj[src])
        {
            if (dst == parent)
            {
                continue;
            }

            if (vis[dst])
            {
                low[src] = min(low[src], low[dst]);
            }
            else
            {
                dfs(adj, dst, src, vis, tin, low, bridges);
                low[src] = min(low[src], low[dst]);
                if (low[dst] > tin[src])
                {
                    bridges.push_back({src, dst});
                }
            }
        }
    }

public:
    vector<vector<int>> findBridges(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);
        vector<int> tin(n);
        vector<int> low(n);
        vector<vector<int>> bridges;

        dfs(adj, 0, -1, vis, tin, low, bridges);

        return bridges;
    }
};

int main()
{
}
