// Given an integer N. Find maximum LCM (Least Common Multiple) that can be obtained from four numbers less than or equal to N.
// Note: Duplicate numbers can be used.

// Example 1:

// Input:
// N = 4
// Output: 12
// Explanation:
// The four numbers can be [4,4,3,2] or
// [4,4,4,3], etc. It can be shown that 12 is
// the maximum LCM of four numbers that can
// be obtained from numbers less than or equal 
// to 4.
// Example 2:

// Input:
// N = 5
// Output: 60
// Explanation:
// The four numbers can be [5,5,4,3] or
// [5,4,3,2], etc. 60 is the maximum that can
// be obtained.


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long gcd(long long A, long long B) {
        if (B == 0) return A;
        return gcd(B, A % B);
    }
    long long lcm(int N){
        if (N == 4) return 12;
        long long a = N * (N - 1);
        long long b = a;
        b *= (N - 2) / gcd(b, N - 2);
        b *= (N - 3) / gcd(b, N - 3);
        long long c = a, f = 0;
        for (int i = N - 2; i >= 1; i--) {
            if (gcd(c, i) == 1) {
                a *= i;
                c *= i;
                f++;
            }
            if (f == 2) break;
        }
        return max(a, b);
    }
    long long maxGcd(int N) {
        if(N==4)return 12;
        return max(lcm(N),lcm(N-1));
        
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.maxGcd(N) << "\n";
    }
}