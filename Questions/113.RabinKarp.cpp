#include <bits/stdc++.h>
using namespace std;
int p = 31;
const int N = 1e5 + 2, m = 1e9 + 7;
vector<long long> powers(N);
int main()
{
    string s = "hi";
    string t = "himanshi";
    int T = t.size(), S = s.size();
    powers[0] = 1;
    for (int i = 0; i < N; i++)
        powers[i] = (powers[i - 1] * p) % m;
    vector<long long> h(T + 1, 0);
    for (int i = 0; i < T; i++)
    {
        h[i + 1] = (h[i] + (t[i] - 'a' + 1) * powers[i]) % m;
    }
    long long hs = 0;
    for (int i = 0; i < S; i++)
    {
        hs = (hs + (s[i] - 'a' + 1) * powers[i]) % m;
    }
    for (int i = 0; i + S - 1 < T; i++)
    {
        long long curh = (h[i + S] - h[i] + m) % m;
        if (curh == (hs * powers[i]) % m)
        {
            cout << "found at index " << i << endl;
        }
    }
    return 0;
}