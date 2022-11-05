#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjm(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++)
    {

        int x, y;
        cin >> x >> y;
        adjm[x][y] = 1;
        adjm[y][x] = 1;
    }
    cout << "adjacency matrix is as follows" << endl;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            cout << adjm[i][j] << " ";
        }
        cout << endl;
    }
    const int N = 1e5 + 2, MOD = 1e9 + 7;
    cout << endl
         << endl;
    cin >> n >> m;
    vector<int> adj[N];
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout << "the adjacency list of the above graph is as follows" << endl;
    for (int i = 1; i < n + 1; i++)
    {
        cout << i << "=>";
        vector<int>::iterator it;
        for (it = adj[i].begin(); it != adj[i].end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    return 0;
}