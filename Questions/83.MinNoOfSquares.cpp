#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2, mod = 1e9 + 7;
int dp[N];
int MinSquare(int n)
{
    if (n == 0 || n == 1 || n == 2 || n == 3)
    {
        return n;
    }
    if (dp[n] != mod)
        return dp[n];
    for (int i = 1; i * i <= n; i++)
    {
        dp[n] = min(dp[n], 1 + MinSquare(n - i * i));
    }
    return dp[n];
}
int main()
{
    for (int i = 0; i < N; i++)
        dp[i] = mod;
    int n;
    cin >> n;
    cout << MinSquare(n);
    return 0;
}