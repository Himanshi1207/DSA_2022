// Given a number k and string num of digits (0 to 9) denoting a positive integer. Find a string denoting the lowest integer number possible by removing k digits from num, without changing their order.
// Note: num will not contain any leading zero.

// Example 1:

// Input:
// k = 2
// num = "143729"
// Output: "1329"
// Explanation: 1329 is the minimum number
// possible after removing '4' and '7'.

#include <bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
int main()
{
    int t, n;
    string str;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> str;
        cout << buildLowestNumber(str, n) << endl;
    }
    return 0;
}

string buildLowestNumber(string num, int k)
{
    // code here.
    stack<char> st;
    st.push(num[0]);
    int n = num.size();
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() and st.top() > num[i] and k > 0)
        {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    while (k > 0)
    {
        st.pop();
        --k;
    }
    string ans = "";
    while (!st.empty())
    {
        ans = st.top() + ans;
        st.pop();
    }
    int l = -1;
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] != '0')
            break;
        l = i;
    }
    if (l == ans.size() - 1)
        return "0";
    if (l >= 0)
        return ans.substr(l + 1);
    return ans;
}