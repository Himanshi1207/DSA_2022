// TAG -> Medium 
// Link -> https://leetcode.com/contest/weekly-contest-326/problems/distinct-prime-factors-of-product-of-array/

// Given an array of positive integers nums, return the number of distinct prime factors in the product of the elements of nums.

// Note that:

// A number greater than 1 is called prime if it is divisible by only 1 and itself.
// An integer val1 is a factor of another integer val2 if val2 / val1 is an integer.
 

// Example 1:

// Input: nums = [2,4,3,7,10,6]
// Output: 4
// Explanation:
// The product of all the elements in nums is: 2 * 4 * 3 * 7 * 10 * 6 = 10080 = 25 * 32 * 5 * 7.
// There are 4 distinct prime factors so we return 4.
// Example 2:

// Input: nums = [2,4,8,16]
// Output: 1
// Explanation:
// The product of all the elements in nums is: 2 * 4 * 8 * 16 = 1024 = 210.
// There is 1 distinct prime factor so we return 1.
 

// Constraints:

// 1 <= nums.length <= 104
// 2 <= nums[i] <= 1000

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void isprime(int it, unordered_set<int> &s){
        while(it%2==0)
        {
        s.insert(2);
        it/=2;    
        }   
        for(int i=3;i<=sqrt(it);i++){
            while(it%i==0){
                s.insert(i);
                it/=i;
            }
        }
        if(it>2){
            s.insert(it);
        }
        
    }
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> primeFactors;
        for(auto it: nums){
            isprime(it,primeFactors);
        }
        return primeFactors.size();
    }
};