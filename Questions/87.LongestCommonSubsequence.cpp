#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;
int dp[N][N];
int lcs(string &s1, string &s2, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    if (s1[n - 1] == s2[m - 1])
        dp[n][m] = 1 + lcs(s1, s2, n - 1, m - 1);
    else
    {
        dp[n][m] = max(lcs(s1, s2, n, m - 1), lcs(s1, s2, n - 1, m));
    }
    return dp[n][m];
}
int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            dp[i][j] = -1;
    }
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    cout << lcs(s1, s2, n, m) << endl;
    return 0;
}