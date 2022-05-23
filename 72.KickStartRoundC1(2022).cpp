#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int arr[4] = {0};
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9')
            {
                arr[0] = 1;
            }
            else if (s[i] == '#' || s[i] == '@' || s[i] == '*' || s[i] == '&')
            {
                arr[1] = 1;
            }
            else if ((s[i] >= 'a' && s[i] <= 'z'))
            {
                arr[2] = 1;
            }
            else if ((s[i] >= 'A' && s[i] <= 'Z'))
            {
                arr[3] = 1;
            }
        }
        if (arr[0] == 0)
        {
            s += '1';
        }
        if (arr[1] == 0)
        {
            s += '@';
        }
        if (arr[2] == 0)
        {
            s += 'a';
        }
        if (arr[3] == 0)
        {
            s += 'A';
        }
        if (s.size() < 7)
        {
            int size=s.size();
            for (int i = 0; i < 7 - size; i++)
            {
                s += "a";
            }
        }

        cout << "Case #" << i << ": " << s << endl;
    }
    return 0;
}