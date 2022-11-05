// Given an array arr[] of size N and an integer K. The task is to find the minimum number of elements that should be removed, such that Amax-Amin<=K. After the removal of elements, Amax and Amin is considered among the remaining elements. 

// Note: Can you solve the probelm without using any extra space and O(N*log(N)) time complexity?

// Example 1:

// Input: N = 9, K = 4  
// arr[] = {1,3,4,9,10,11,12,17,20}
// Output: 5
// Explanation: Remove 1, 3, 4 from beginning
// and 17, 20 from the end.

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int removals(vector<int>& arr, int k){

        sort(arr.begin(),arr.end());

        int i=0,j=0;

        int ans=0;

        for(int i=0;i<arr.size();i++)

        {

            while(arr[i]-arr[j]>k)

            {

                j++;

            }

            ans=max(ans,i-j+1);

        }

        

        return arr.size()-ans;

    }
};