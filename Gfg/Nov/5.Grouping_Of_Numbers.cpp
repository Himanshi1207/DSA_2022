// One day Jim came across array arr[] of N numbers. He decided to divide these N numbers into different groups. Each group contains numbers in which sum of any two numbers should not be divisible by an integer K. Print the size of the group containing maximum numbers.

 

// Example 1:

// Input:
// N = 4, K = 8
// arr[] = {1, 7, 2, 6}
// Output:
// 2
// Explanation:
// The  group of numbers which can be formed
// are: (1),(2),(7),(6),(1,2),(1,6),(7,2),(7,6).
// So,the maximum possible size of the group is 2.


#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxGroupSize(int arr[], int n, int k) {
        // code here
        int rem[k];
        memset(rem, 0, sizeof(rem));
        for(int i=0; i<n; i++){
            rem[ arr[i]%k ]++;
        }

        int ans=0;
        int i=1, j=k-1;
       //pick max of (i, k-i)
        while(i<j){
            ans+= max(rem[i++], rem[j--]);
        }
        if(rem[0]!=0){
            ans++;
        }
        // if k is even pick the middle element only one time as
        //(k/2+k/2)%k=0;
        if((k&1)==0 and rem[k/2]) ans++;
        
        return ans;
    }
};