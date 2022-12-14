// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

#include<bits/stdc++.h>
using namespace std;
const int N=400;
int dp[N+1];

class Solution {
public:
    int rob(vector<int>& nums) {
        int ans=0;
        dp[0]=0;
        dp[1]=nums[0];
        if(nums.size()==1)
            return dp[1];
        for(int i=2;i<=nums.size();i++){
            if(i==0)
                dp[i]=0;
            else{
                dp[i]=max(nums[i-1]+dp[i-2], dp[i-1]);
            }
            ans=max(ans, dp[i]);
        }
        return ans;
    }
};