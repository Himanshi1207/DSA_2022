#include <bits/stdc++.h>
using namespace std;
bool bipart;
vector<int> col;
vector<bool> vis;
vector<vector<int>> adj;
void color(int u, int curr)
{
    // cout << "function";
    if (col[u] != -1 and col[u] != curr)
    {
        bipart = false;
        return;
    }
    col[u] = curr;
    if (vis[u])
    {
        return;
    }
    vis[u] = true;
    for (auto i : adj[u])
    {
        color(i, curr xor 1);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    bool bipart = true;
    adj = vector<vector<int>>(n);
    vis = vector<bool>(n, false);
    col = vector<int>(n, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            color(i, 0);
        }
    }
    if (bipart)
    {
        cout << "Bipartite Graph";
    }
    else
    {
        cout << "NOT Bipartite Graph" << endl;
    }
    return 0;
}