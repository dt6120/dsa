#include <bits/stdc++.h>

using namespace std;

void topoSortDFS(vector<vector<int>> &adj, int src, vector<int> &vis, vector<int> &path)
{
    if (vis[src])
    {
        return;
    }

    vis[src] = 1;

    for (int dst : adj[src])
    {
        topoSortDFS(adj, dst, vis, path);
    }

    path.push_back(src);
}

// Also known as KAHN'S ALGORITHM
vector<int> topoSortBFS(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> inDegree(n, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < adj[i].size(); i++)
        {
            inDegree[j]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> path;

    while (!q.empty())
    {
        int src = q.front();
        q.pop();

        path.push_back(src);

        for (int dst : adj[src])
        {
            inDegree[dst]--;
            if (inDegree[dst] == 0)
            {
                q.push(dst);
            }
        }
    }

    return path;
}

int main()
{
}
