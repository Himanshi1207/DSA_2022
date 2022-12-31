// Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.
 

// Example 1 :

// Input : arr = [9, 5, 7, 3], k = 6
// Output: True
// Explanation: {(9, 3), (5, 7)} is a 
// possible solution. 9 + 3 = 12 is divisible
// by 6 and 7 + 5 = 12 is also divisible by 6.
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        unordered_map<int, int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]%k]++;
        }
        if(freq.find(0)!=freq.end())

            if(freq[0]%2!=0)   return false;

        for(auto i : freq)

            if(i.first!=0 and freq[i.first] != freq[k-i.first])   return false;

        return true;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}