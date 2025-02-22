#include <bits/stdc++.h>

using namespace std;

class DisjointSet
{
private:
    vector<int> size;
    vector<int> parent;

public:
    DisjointSet(int n)
    {
        size = vector<int>(n + 1, 1);
        parent = vector<int>(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int u)
    {
        if (parent[u] == u)
        {
            return u;
        }

        return parent[u] = findParent(parent[u]);
    }

    bool unionBySize(int u, int v)
    {
        int pu = findParent(u), pv = findParent(v);
        if (pu == pv)
        {
            return false;
        }

        if (size[pu] <= size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }

        return true;
    }
};

int kruskalsMstAlgorithm(int n, vector<vector<int>> &edges)
{
    // edges: { wt, u, v }
    sort(edges.begin(), edges.end());

    DisjointSet *ds = new DisjointSet(n);
    vector<vector<int>> mst;
    int sum = 0;

    for (auto e : edges)
    {
        if (ds->unionBySize(e[1], e[2]))
        {
            mst.push_back({e[1], e[2]});
            sum += e[0];
        }
    }

    return sum;
}

int main() {}