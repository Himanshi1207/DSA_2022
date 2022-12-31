// Given an integer n, return the least number of perfect square numbers that sum to n.

// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

// Example 1:

// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        int count=1;
        while(count*count<=n){
            int sq=count*count;
            for(int i=sq;i<n+1;i++){
                dp[i]=min(dp[i-sq]+1, dp[i]);
            }
            count++;
        }
        return dp[n];
    }
};