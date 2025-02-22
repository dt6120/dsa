#include <bits/stdc++.h>

using namespace std;

// finds shortest path from all nodes to all other nodes
// also helps to detect negative cycles

void floydWarshall(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++)
    {
        dist[i][i] = 0;
    }

    for (auto e : edges)
    {
        dist[e[0]][e[1]] = e[2];
    }

    // go via node i
    for (int i = 0; i < n; i++)
    {
        // start from j
        for (int j = 0; j < n; j++)
        {
            // end at k
            for (int k = 0; k < n; k++)
            {
                if (
                    dist[j][i] != INT_MAX &&
                    dist[i][k] != INT_MAX &&
                    dist[j][i] + dist[i][k] < dist[j][k])
                {
                    dist[j][k] = dist[j][i] + dist[i][k];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (dist[i][i] < 0)
        {
            cout << "Negative cycle exists" << endl;
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n = 3;
    // vector<vector<int>> edges = {{0, 1, 2}, {1, 0, 1}, {1, 2, 3}, {3, 0, 3}, {3, 1, 5}, {3, 2, 4}};
    vector<vector<int>> edges = {{0, 1, -2}, {1, 2, -3}, {2, 0, 2}};
    // vector<vector<pair<int, int>>> adj(n);

    // for (auto e : edges)
    // {
    //     adj[e[0]].push_back({e[1], e[2]});
    // }

    floydWarshall(n, edges);
}
