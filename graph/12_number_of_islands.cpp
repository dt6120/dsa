#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

class DisjointSet
{
private:
    vector<int> size;
    vector<int> parent;
    int m, n;

public:
    DisjointSet(int m, int n)
    {
        this->m = m;
        this->n = n;
        int count = m * n;

        size = vector<int>(count, 1);
        parent = vector<int>(count);

        for (int i = 0; i <= count; i++)
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

int markLandCell(pair<int, int> src, vector<vector<int>> &vis, DisjointSet *ds, int count)
{
    int m = vis.size(), n = vis[0].size();
    auto [x, y] = src;
    if (vis[x][y])
    {
        return count;
    }
    vis[x][y] = 1;
    count++;

    for (auto d : dir)
    {
        int dx = x + d.first, dy = y + d.second;
        if (dx >= 0 && dx < m && dy >= 0 && dy < n && vis[dx][dy])
        {
            int u = x * n + y, v = dx * n + dy;
            if (ds->unionBySize(u, v))
            {
                count--;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << vis[i][j] << " ";
        }
        cout << endl;
    }

    return count;
}

int main()
{
    int m = 4, n = 5, count = 0;
    vector<vector<int>> vis(m, vector<int>(n, 0));
    DisjointSet *ds = new DisjointSet(m, n);

    count = markLandCell({0, 0}, vis, ds, count);
    cout << count << endl;
    count = markLandCell({0, 0}, vis, ds, count);
    cout << count << endl;
    count = markLandCell({1, 1}, vis, ds, count);
    cout << count << endl;
    count = markLandCell({1, 0}, vis, ds, count);
    cout << count << endl;
    count = markLandCell({0, 1}, vis, ds, count);
    cout << count << endl;
    count = markLandCell({0, 3}, vis, ds, count);
    cout << count << endl;
    count = markLandCell({1, 3}, vis, ds, count);
    cout << count << endl;
    count = markLandCell({0, 4}, vis, ds, count);
    cout << count << endl;
    count = markLandCell({3, 2}, vis, ds, count);
    cout << count << endl;
    count = markLandCell({2, 2}, vis, ds, count);
    cout << count << endl;
    count = markLandCell({1, 2}, vis, ds, count);
    cout << count << endl;
    count = markLandCell({0, 2}, vis, ds, count);
    cout << count << endl;
    count = markLandCell({1, 4}, vis, ds, count);
    cout << count << endl;
}
