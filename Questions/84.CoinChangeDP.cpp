#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;
int dp[N][N];
int coinChange(vector<int> &a, int n, int x)
{
    if (x == 0)
        return 1;
    if (x < 0)
        return 0;
    if (n <= 0)
        return 0;
    if (dp[n][x] != -1)
        return dp[n][x];
    dp[n][x] = coinChange(a, n, x - a[n - 1]) + coinChange(a, n - 1, x);
    return dp[n][x];
}
int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            dp[i][j] = -1;
    }
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int x;
    cin >> x;
    cout << coinChange(a, n, x);
    return 0;
}