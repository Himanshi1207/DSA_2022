#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int sum = 0, ans = INT_MAX;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < k; i++)
    {
        sum += a[i];
    }
    for (int i = 1; i < n - k + 1; i++)
    {
        sum -= a[i - 1];
        sum += a[i + k - 1];
        ans = min(sum, ans);
    }
    cout << ans << endl;
    return 0;
}