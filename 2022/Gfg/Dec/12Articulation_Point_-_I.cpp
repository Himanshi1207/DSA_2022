// Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components.
// Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.

// Example 1:

// Input:

// Output:{1,4}
// Explanation: Removing the vertex 1 will
// discconect the graph as-

// Removing the vertex 4 will disconnect the
// graph as-


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int timer = 0;
    void dfs(int node, int parent, vector<int> &vis, int tin[], int low[], vector<int> &mark, vector<int> adj[])
    {
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        int child = 0;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (!vis[it])
            {
                dfs(it, node, vis, tin, low, mark, adj);
                low[node] = min(low[node], low[it]);
                if (low[it] >= tin[node] and parent != -1)
                    mark[node] = 1;
                child++;
            }
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }
        if (child > 1 and parent == -1)
            mark[node] = 1;
    }
    vector<int> articulationPoints(int n, vector<int> adj[])
    {
        // Code here
        vector<int> visited(n, 0);
        int tin[n], low[n];
        vector<int> mark(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, -1, visited, tin, low, mark, adj);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (mark[i] == 1)
            {
                ans.push_back(i);
            }
        }
        if (ans.size() == 0)
            return {-1};
        return ans;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, adj);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}