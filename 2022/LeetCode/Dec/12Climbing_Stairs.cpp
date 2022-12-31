// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps

#include<bits/stdc++.h>
using namespace std;
const int N=46;
int dp[N]={0};
class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
        {
            dp[n]=1;
            return 1;
        }
        if(n==2)
        {
            dp[n]=2;
            return 2;
        }
        else if(dp[n]!=0)
            return dp[n];
        dp[n]=climbStairs(n-1)+climbStairs(n-2);
        return dp[n];
    }
};