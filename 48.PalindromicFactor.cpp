// Problem
// You are given a positive integer A. Find the number of factors of A which are palindromes. A number is called a palindrome if it remains the same when the digits in decimal representation are reversed. For instance, 121 is a palindrome, while 123 is not.

// Input
// The first line of the input gives the number of test cases, T. T lines follow.

// Each line represents a test case and contains a single integer A.

// Output
// For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the number of factors of A which are palindromes.

// Limits
// Time limit: 2 seconds.
// Memory limit: 1 GB.
// 1≤T≤100.
// Test Set 1
// 1≤A≤103.
// Test Set 2
// 1≤A≤1010.
// Sample
// Sample Input
// save_alt
// content_copy
// 4
// 6
// 10
// 144
// 242
// Sample Output
// save_alt
// content_copy
// Case #1: 4
// Case #2: 3
// Case #3: 7
// Case #4: 6
// In the first test case, A has 4 factors which are palindromes: 1,2,3, and 6.
// In the second test case, A has 3 factors which are palindromes: 1,2, and 5.
// In the third test case, A has 7 factors which are palindromes: 1,2,3,4,6,8, and 9.
// In the fourth test case, A has 6 factors which are palindromes: 1,2,11,22,121, and 242.
#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(int a)
{
    if (a < 0)
        return true;
    int temp = a;
    int num = 0;
    while (a > 0)
    {
        int remainder = 0;
        remainder = a % 10;
        num = num * 10 + remainder;
        a /= 10;
    }
    if (temp == num)
        return true;

    return false;
}
int main()
{
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        int a;
        cin >> a;
        int ans = 0;
        for (int i = 1; i <= sqrt(a); i++)
        {
            if (a % i == 0)
            {
                if (a / i == i)
                {
                    if (isPalindrome(i))
                        ans++;
                    // cout <<" "<< i;
                }

                else
                {
                    if (isPalindrome(i))
                        ans++;
                    if (isPalindrome(a / i))
                        ans++;
                    // cout << " "<< i << " " << a/i;
                } // Otherwise print both
            }
        }
        cout << "Case #" << k << ": " << ans << endl;
    }

    return 0;
}