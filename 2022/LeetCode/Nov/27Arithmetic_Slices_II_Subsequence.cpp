// Given an integer array nums, return the number of all the arithmetic subsequences of nums.

// A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

// For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic sequences.
// For example, [1, 1, 2, 5, 7] is not an arithmetic sequence.
// A subsequence of an array is a sequence that can be formed by removing some elements (possibly none) of the array.

// For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
// The test cases are generated so that the answer fits in 32-bit integer.

 

// Example 1:

// Input: nums = [2,4,6,8,10]
// Output: 7
// Explanation: All arithmetic subsequence slices are:
// [2,4,6]
// [4,6,8]
// [6,8,10]
// [2,4,6,8]
// [4,6,8,10]
// [2,4,6,8,10]
// [2,6,10]

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        vector<unordered_map<long,long>> dp(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                long cd=(long)nums[i]-(long)nums[j];
                dp[i][cd]++;
                if(dp[j].find(cd)!=dp[j].end()){
                    dp[i][cd]+=dp[j][cd];
                    ans+=dp[j][cd];
                }
            }
        }
        return ans;
    }
};