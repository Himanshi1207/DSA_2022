// Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.

 

// Example 1:

// Input: nums = [4,6,7,7]
// Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
// Example 2:

// Input: nums = [4,4,3,2,1]
// Output: [[4,4]]
 

// Constraints:

// 1 <= nums.length <= 15
// -100 <= nums[i] <= 100

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void subs(vector<int> &nums, int idx, set<vector<int>> &ans, vector<int> &vec){
        int n=nums.size(); 
        if(idx>=n){
            if(vec.size()>=2){
                //if we have such subarray we will insert it to the set
                ans.insert(vec);
            }
            return ;
        }
// //         take
        
         if(!vec.size() or vec.back()<=nums[idx]){     
            vec.push_back(nums[idx]);
            subs(nums, idx+1, ans, vec);
            vec.pop_back();
        }
//         not take case
        subs(nums, idx+1, ans, vec);      
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
       set<vector<int>> ans;
        // if(nums.size()==1){
        //     return ans;
        // }
        vector<int> vec;
        subs(nums, 0, ans, vec);
        return vector(ans.begin(), ans.end());
    }
};
  