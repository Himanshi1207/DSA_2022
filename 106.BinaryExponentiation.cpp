#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2, mod = 1e9 + 7;
int power(int a, int n)
{
    a %= mod;
    int ans = 1;
    while (n > 0)
    {
        if (n & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        n = n >> 1;
    }
    return ans;
}
int main()
{
    int a, n;
    cin >> a >> n;
    cout << power(a, n) << endl;
    return 0;
}