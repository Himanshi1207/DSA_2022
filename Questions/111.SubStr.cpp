#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "hi";
    string t = "himanshi himanshi";
    int S = s.size(), T = t.size();
    for (int i = 0; i < T - S + 1; i++)
    {
        if (t.substr(i, S) == s)
            cout << "found at index " << i << endl;
    }
}