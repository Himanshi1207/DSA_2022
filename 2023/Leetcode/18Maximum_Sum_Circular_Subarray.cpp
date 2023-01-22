// Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

// A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

// A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

// Example 1:

// Input: nums = [1,-2,3,-2]
// Output: 3
// Explanation: Subarray [3] has maximum sum 3.
// Example 2:

// Input: nums = [5,-3,5]
// Output: 10
// Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
// Example 3:

// Input: nums = [-3,-2,-3]
// Output: -2
// Explanation: Subarray [-2] has maximum sum -2.
 

// Constraints:

// n == nums.length
// 1 <= n <= 3 * 104
// -3 * 104 <= nums[i] <= 3 * 104
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
    bool positive=false; int sum=0,maxi=nums[0];
        int cmax1=0,gmax1=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) positive=true;
            sum+=nums[i];
            maxi=max(maxi,nums[i]); 
            cmax1+=nums[i]; //kadane's algorithm
            if(nums[i]>cmax1) cmax1=nums[i];
            gmax1=max(gmax1,cmax1);
            nums[i]*=-1; //inverting all array elements 
        }

        if(!positive) return maxi; //if all elements of the array are -ve, we just return max element.
      int cmax2=0,gmax2=nums[0];
        for(auto x: nums){
            cmax2+=x; //kadane's algo on inverted array
            if(x>cmax2) cmax2=x;
            gmax2=max(gmax2,cmax2);
        }
 //gmax1=kadane's solution of one-interval and gmax2=kadane's solution of two-interval subarray       
        int remove=-1*(gmax2); //min sum subarray to be removed
        return max(sum-remove,gmax1);

    }
};