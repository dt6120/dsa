#include <bits/stdc++.h>

using namespace std;

class DisjointSet
{
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

public:
    DisjointSet(int n)
    {
        rank = vector<int>(n + 1, 0);
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

        // this results in path compression
        // without dp, it takes log(H) time
        return parent[u] = findParent(parent[u]);
    }

    // due to path compression, rank does not always store correct data
    void unionByRank(int u, int v)
    {
        int pu = findParent(u), pv = findParent(v);
        if (pu == pv)
        {
            return;
        }

        // join lower rank leader to bigger rank leader
        // bigger rank leader's rank will not change after union
        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pu] = pv;
            rank[pv]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int pu = findParent(u), pv = findParent(v);
        if (pu == pv)
        {
            return;
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
    }
};

int main() {}
