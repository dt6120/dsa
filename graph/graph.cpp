#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    string val;
    Node(string x)
    {
        val = x;
    }
};

class Graph
{
private:
    vector<Node *> nodes;
    vector<vector<bool>> adjMatrix;

public:
    void addNode(Node *node)
    {
        nodes.push_back(node);
        int curSize = adjMatrix.size();
        int newSize = nodes.size();

        for (int i = 0; i < curSize; i++)
        {
            adjMatrix[i].push_back(false);
        }
        vector<bool> newRow(newSize);
        adjMatrix.push_back(newRow);
    }

    void addEdge(int src, int dst)
    {
        adjMatrix[src][dst] = true;
    }

    bool checkEdge(int src, int dst)
    {
        return adjMatrix[src][dst];
    }

    void dfs(int src)
    {
        vector<bool> visited(adjMatrix.size());
        dfsHelper(src, visited);
    }

    void dfsHelper(int src, vector<bool> &visited)
    {
        if (visited[src])
        {
            return;
        }

        visited[src] = true;
        cout << "Visited node with data " << nodes[src]->val << endl;

        for (int i = 0; i < adjMatrix[src].size(); i++)
        {
            // once you reach a deadend
            // backtrack to a node
            // with unvisited adjacent nodes

            if (src == i)
            {
                continue;
            }

            if (checkEdge(src, i))
            {
                dfsHelper(i, visited);
            }
        }

        return;
    }

    void bfs(int src)
    {
        vector<bool> visited(adjMatrix.size());
        queue<int> queue;

        queue.push(src);
        visited[src] = true;

        while (!queue.empty())
        {
            int t = queue.front();
            queue.pop();
            cout << "Visited node with data " << nodes[t]->val << endl;

            for (int i = 0; i < adjMatrix[t].size(); i++)
            {
                if (t != i && checkEdge(t, i) && !visited[i])
                {
                    queue.push(i);
                    visited[i] = true;
                }
            }
        }
    }
};

int main()
{
    Graph *graph = new Graph();

    graph->addNode(new Node("A"));
    graph->addNode(new Node("B"));
    graph->addNode(new Node("C"));
    graph->addNode(new Node("D"));
    graph->addNode(new Node("E"));

    graph->addEdge(0, 1);
    graph->addEdge(1, 2);
    graph->addEdge(1, 4);
    graph->addEdge(2, 3);
    graph->addEdge(2, 4);
    graph->addEdge(4, 0);
    graph->addEdge(4, 2);

    graph->bfs(1);

    bitset<5> bs("11111");
    cout << bs << endl;
    cout << bs.flip() << endl;
    cout << bs << endl;
}
