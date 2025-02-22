#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void dfs(vector<vector<int>> &grid, int x, int y, int i, int j, vector<vector<int>> &vis, vector<pair<int, int>> &coord)
{
    int m = grid.size(), n = grid[0].size();

    if (vis[x][y])
    {
        return;
    }

    vis[x][y] = 1;
    coord.push_back({x - i, y - j});

    for (auto d : dir)
    {
        int dx = x + d.first, dy = y + d.second;
        if (dx >= 0 && dx < m && dy >= 0 && dy < n && grid[dx][dy] == 1 && vis[dx][dy] == 0)
        {
            dfs(grid, dx, dy, i, j, vis, coord);
        }
    }
}

int main()
{
    vector<vector<int>> grid = {{1, 1, 0, 1, 1}, {1, 0, 0, 0, 0}, {0, 0, 0, 0, 1}, {1, 1, 0, 1, 1}};

    int m = grid.size(), n = grid[0].size();

    vector<vector<int>> vis(m, vector<int>(n, 0));

    set<vector<pair<int, int>>> islands;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1 && vis[i][j] == 0)
            {
                vector<pair<int, int>> coord;
                dfs(grid, i, j, i, j, vis, coord);
                islands.insert(coord);
            }
        }
    }

    cout << "distinct islands " << islands.size() << endl;
}