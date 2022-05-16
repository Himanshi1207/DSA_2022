#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <set>
#include <vector>
#define pii pair<int, int>
using namespace std;
int main()
{
    int k;
    cin >> k; // how many vectors or arrays
    vector<vector<int>> a(k);
    for (int i = 0; i < k; i++)
    {
        int size;
        cin >> size;
        a[i] = vector<int>(size);
        for (int j = 0; j < size; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<int> idx(k, 0);
    vector<int> ans;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push({a[i][0], i});
    }
    while (!pq.empty())
    {
        pii x = pq.top();
        pq.pop();
        ans.push_back(x.first);
        if (idx[x.second] + 1 < a[x.second].size())
            pq.push({a[x.second][idx[x.second] + 1], x.second});
        idx[x.second] += 1;
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    cout << endl;
    return 0;
}