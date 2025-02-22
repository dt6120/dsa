#include <bits/stdc++.h>

using namespace std;

// Kosaraju's algorithm is used to find the number of strongly connected components
// SCC is a graph component in which every node is reachable from every other node

void dfs(vector<vector<int>> &adj, int src, vector<int> &vis, stack<int> &st)
{
    vis[src] = 1;

    for (int dst : adj[src])
    {
        if (!vis[dst])
        {
            dfs(adj, dst, vis, st);
        }
    }

    st.push(src);
}

void dfsT(vector<vector<int>> &adj, int src, vector<int> &vis)
{
    vis[src] = 1;

    for (int dst : adj[src])
    {
        if (!vis[dst])
        {
            dfsT(adj, dst, vis);
        }
    }
}

int kosarajusSccAlgorithm(int n, vector<vector<int>> &adj)
{
    vector<int> vis(n, 0);
    stack<int> st;

    // sort the nodes in terms of finishing time
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(adj, i, vis, st);
        }
    }

    // reverse the edges
    vector<vector<int>> adjT(n);
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
        for (auto j : adj[i])
        {
            adjT[j].push_back(i);
        }
    }

    // traverse the graph
    int sccCount = 0;
    while (!st.empty())
    {
        int src = st.top();
        st.pop();
        if (!vis[src])
        {
            dfsT(adjT, src, vis);
            sccCount++;
        }
    }

    return sccCount;
}

int main() {}
