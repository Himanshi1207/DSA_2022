#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> val(n);
    vector<int> wt(n);
    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    int w;
    cin >> w;
    vector<int> dp(w + 1, 0);
    for (int j = 0; j <= w; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (j - wt[i] >= 0)
                dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);
        }
    }
    cout << dp[w] << endl;
    return 0;
}