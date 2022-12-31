// Given the chessboard dimensions. Find out the number of ways we can place a black and a white Knight on this chessboard such that they cannot attack each other.

// Note:
// The knights have to be placed on different squares. A knight can move two squares horizontally and one square vertically (L shaped), or two squares vertically and one square horizontally (L shaped). The knights attack each other if one can reach the other in one move.

// Example 1:

// Input:
// N = 2, M = 2
// Output: 12 
// Explanation: There are 12 ways we can place a black and a white Knight on this chessboard such that they cannot attack each other.

#include <bits/stdc++.h>

using namespace std;
long long numOfWays(int n, int m)
{
    // write code here
    long long mod=1000000007;
    long long total=((n*m)%mod*(n*m-1)%mod)%mod;
    
    if(n>=1 && m>=2)
    {
        total-=4*(n-1)*(m-2);
    }
    if(n>=2 && m>=1)
    {
        total-=4*(n-2)*(m-1);
    }
    
    return total;
    
    
}


int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}