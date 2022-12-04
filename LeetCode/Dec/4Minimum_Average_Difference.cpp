// You are given a 0-indexed integer array nums of length n.

// The average difference of the index i is the absolute difference between the average of the first i + 1 elements of nums and the average of the last n - i - 1 elements. Both averages should be rounded down to the nearest integer.

// Return the index with the minimum average difference. If there are multiple such indices, return the smallest one.

// Note:

// The absolute difference of two numbers is the absolute value of their difference.
// The average of n elements is the sum of the n elements divided (integer division) by n.
// The average of 0 elements is considered to be 0.
 

// Example 1:

// Input: nums = [2,5,3,9,5,3]
// Output: 3
// Explanation:
// - The average difference of index 0 is: |2 / 1 - (5 + 3 + 9 + 5 + 3) / 5| = |2 / 1 - 25 / 5| = |2 - 5| = 3.
// - The average difference of index 1 is: |(2 + 5) / 2 - (3 + 9 + 5 + 3) / 4| = |7 / 2 - 20 / 4| = |3 - 5| = 2.
// - The average difference of index 2 is: |(2 + 5 + 3) / 3 - (9 + 5 + 3) / 3| = |10 / 3 - 17 / 3| = |3 - 5| = 2.
// - The average difference of index 3 is: |(2 + 5 + 3 + 9) / 4 - (5 + 3) / 2| = |19 / 4 - 8 / 2| = |4 - 4| = 0.
// - The average difference of index 4 is: |(2 + 5 + 3 + 9 + 5) / 5 - 3 / 1| = |24 / 5 - 3 / 1| = |4 - 3| = 1.
// - The average difference of index 5 is: |(2 + 5 + 3 + 9 + 5 + 3) / 6 - 0| = |27 / 6 - 0| = |4 - 0| = 4.
// The average difference of index 3 is the minimum average difference so return 3.


#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
int minimumAverageDifference(vector<int>& nums) {
    int n=nums.size();
    if(n==1)    return 0;
    long long pre[n]; //to store prefix sum
    pre[0]=nums[0];
	
	//calculating prefix sum
    for(int i=1;i<n;i++)    pre[i]=pre[i-1]+nums[i];
	
    long long res=INT_MAX;
    int ind=0;
	
	// calculating minimum average for i=0 to i=n-2
    for(int i=1;i<n;i++) {
        int k=(abs(pre[i-1]/i-(pre[n-1]-pre[i-1])/(n-i)));
        if(res>k){
            res=k;
            ind=i-1;
        }
    }
	
	//special case for i=n-1
    if(res>abs(pre[n-1]/n)){
        res=abs(pre[n-1]/n);
        ind=n-1;
    }
    return ind;
}
};








































Alternate Vowel and Consonant String