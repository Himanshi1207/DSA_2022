// Given two binary strings A and B consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
// Note: The input strings may contain leading zeros but the output string should not have any leading zeros.

// Example 1:

// Input:
// A = "1101", B = "111"
// Output: 10100
// Explanation:
//  1101
// + 111
// 10100

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addBinary(string A, string B)
    {
        int a = A.length();
        int b = B.length();
        reverse(A.begin(), A.end());
        reverse(B.begin(), B.end());
        string res = "";
        int carry = 0;
        int i = 0, j = 0;
        while (i < a and j < b)
        {
            int temp = (A[i] - '0') ^ (B[j] - '0') ^ carry;
            carry = ((A[i] - '0') and (B[j] - '0')) or ((A[i] - '0') and carry) or ((B[j] - '0') and carry);
            res += to_string(temp);
            i++;
            j++;
        }
        while (i < a)
        {
            res += to_string(A[i] - '0' ^ carry);
            carry = (A[i] - '0') and carry;
            i++;
        }
        while (j < b)
        {
            res += to_string(B[j] - '0' ^ carry);
            carry = (B[j] - '0') and carry;
            j++;
        }
        if (carry != 0)
            res += to_string(carry);
        while (res[res.length() - 1] == '0')
            res.resize(res.size() - 1);
        reverse(res.begin(), res.end());
        return res;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";
    }
}