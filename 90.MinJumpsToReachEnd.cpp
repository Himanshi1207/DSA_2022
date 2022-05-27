#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> jumps(n, inf);
    if (a[0] == 0)
    {
        cout << inf << " ";
        return 0;
    }
    jumps[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i <= (j + a[j]))
            {
                jumps[i] = min(jumps[i], jumps[j] + 1);
            }
        }
    }
    cout << jumps[n - 1] << endl;
    return 0;
}