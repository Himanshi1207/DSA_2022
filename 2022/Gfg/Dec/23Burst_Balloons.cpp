// You are given N balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array arr. You are asked to brust all the balloons.
// If you brust the ith  balloon,, you will get arr[ i - 1 ] * arr[ i ] * arr[ i + 1] coins. If i - 1, or i + 1 goes out of bounds of the array, consider it as if there is a balloon with a 1 painted on it.
// Return the maximum coins you can collect by brusting the balloons wisely.

// Example 1:

// Input:
// N = 4
// arr[ ] = {3, 1, 5, 8}
// Output: 167
// Explanation: 
// arr[ ] = {3, 1, 5, 8}  - - > {3, 5, 8} - - > {3, 8} - - > { 8} - -> { }
// coins = 3 *1 *5,      +      3*5*8     +   1*3*8   +  1*8*1   = 167
 
 

// Example 2:

// Input:
// N = 2
// arr[ ] = {1, 10}
// Output: 20

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int helper(int i, int j, vector<int> &a, vector<vector<int>> &dp){
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int maxi=INT_MIN;
        for(int ind=i;ind<=j;ind++){
            int cost=a[i-1]*a[ind]*a[j+1]+ helper(i,ind-1,a,dp)+helper(ind+1,j,a,dp);
            maxi=max(maxi, cost);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(int n, vector<int> &a) {
        // code here
        a.push_back(1);
        a.insert(a.begin(),1);
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return helper(1,n,a,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends