// Given a list intervals of n intervals, the ith element [s, e, p] denotes the starting point s, ending point e, and the profit p earned by choosing the ith interval. Find the maximum profit one can achieve by choosing a subset of non-overlapping intervals.

// Two intervals [s1, e1, p1] and [s2, e2, p2] are said to be non-overlapping if [e1 <= s2] and [s1 < s2].

// Example 1:

// Input:
// n = 3
// intervals = {
// {1, 2, 4},
// {1, 5, 7},
// {2, 4, 4}
// }
// Output:
// 8
// Explanation:
// One can choose intervals [1, 2, 4] and [2, 4, 4] for a 
// profit of 8.
// Example 2:

// Input:
// n = 3
// intervals = {
// {1, 4, 4},
// {2, 3, 7},
// {2, 3, 4}
// }
// Output:
// 7
// Explanation:
// One can choose interval [2, 3, 7] for a profit of 7.

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     static bool comp(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }
    
    int upper_bound(vector<vector<int>> &v, int x) {
        int l = 0, h = v.size()-1;
        int ans = v.size();
        
        while(l <= h) {
            int mid = (l+h)/2;
            if(v[mid][0] < x) {
                l = mid+1;
            }
            else {
                h = mid-1;
                ans = min(ans,mid);
            }
        }
        return ans;
    }
    
    int maximum_profit(int n, vector<vector<int>> &v) {
        sort(v.begin(),v.end(),comp);
        vector<int> dp(n,-1);
        
        for(int i = n-1; i >= 0; i--) {
            int ind = upper_bound(v,v[i][1]);
            
            if(ind >= n) dp[i] = v[i][2];
            else dp[i] = v[i][2] + dp[ind];
            
            if(i != n-1) dp[i] = max(dp[i],dp[i+1]);
        }
        
        return dp[0];
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends