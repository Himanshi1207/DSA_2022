// Given an array arr of size n containing non-negative integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference


// Example 1:

// Input: N = 4, arr[] = {1, 6, 11, 5} 
// Output: 1
// Explanation: 
// Subset1 = {1, 5, 6}, sum of Subset1 = 12 
// Subset2 = {11}, sum of Subset2 = 11


#include <bits/stdc++.h>
using namespace std;

class Solution{

  public:
//     int solve(int arr[], int n, int totalSum,int sum, int idx, vector<vector<int>> &dp){
//         if(idx==n)
//             return abs(totalSum-(2*sum));
//         int ex=solve(arr,n, totalSum, sum+0, idx+1,dp);
//         int in=solve(arr,n, totalSum, sum+arr[idx], idx+1,dp);
//         if(dp[idx][sum]!=-1)
//             return dp[idx][sum];
//         return dp[idx][sum]=min(ex, in);
//     }
// 	int minDifference(int arr[], int n)  { 
// 	    // Your code goes here
// 	    int totalSum=0;
// 	    for(int i=0;i<n;i++)
//     	    totalSum+=arr[i];
    	    
//     	vector<vector<int>> dp(n+1, vector<int> (totalSum+1, -1));
//     	return solve(arr, n, totalSum, 0,0,dp);
// 	} 
int minDifference(int arr[], int n)  {
       int sum=0;
       for(int i=0;i<n;i++)
       {
           sum+=arr[i];
       }
       int k=sum;
       vector<vector<bool>>dp(n,vector<bool>(k+1,0));
       for(int i=0;i<n;i++)
       {
           dp[i][0]=1;
       }
       if(arr[0]<=k)
       {
           dp[0][arr[0]]=true;
       }
       for(int index=1;index<n;index++)
       {
           for(int target=1;target<=k;target++)
           {
               bool notake=dp[index-1][target];
               bool take=false;
               if(arr[index]<=target)
                   take=dp[index-1][target-arr[index]];
               dp[index][target]=take|notake;
              
           }
       }
       int mini=1e9;
       for(int s1=0;s1<=(sum/2);s1++)
       {
           if(dp[n-1][s1]==true)
           {
               mini=min(mini,abs((sum-s1)-s1));
           }
       }
       return mini;
    }
};

int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}