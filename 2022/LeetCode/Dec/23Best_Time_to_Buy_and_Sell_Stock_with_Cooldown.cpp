// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

// After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

// Example 1:

// Input: prices = [1,2,3,0,2]
// Output: 3
// Explanation: transactions = [buy, sell, cooldown, buy, sell]
// Example 2:

// Input: prices = [1]
// Output: 0

#include<bits/stdc++.h>
using namespace std;
const int N=5001;
int dp[N][2];
class Solution {
public:
    int helper(int idx, int buy, vector<int> &prices){
        if(idx>=prices.size())
            return 0;
        if(dp[idx][buy]!=-1)
            return dp[idx][buy];
        if(buy==1){
            return dp[idx][buy]=max(-prices[idx]+helper(idx+1,0,prices), 0+helper(idx+1,1,prices));
            
;        }
        return dp[idx][buy]=max(prices[idx]+helper(idx+2, 1,prices), 0+helper(idx+1,0,prices));;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
     return helper(0,1,prices);   
    }
};