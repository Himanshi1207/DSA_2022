// Given n buckets and infinite number of balls. The maximum capacity of each bucket is given in an array capacity[]. Find the number of ways to fill the buckets with balls such that each bucket has atleast 1 ball and all the buckets have distinct number of balls in them.
// Note: Since the answer may be very large, calculate the answer modulo 10^9+7.

// Example 1:

// Input: 
// n = 1
// capacity = [6]
// Output: 6
// Explanation: Since there is only one 
// bucket. It may hold any number of balls 
// ranging from 1 to 6.

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
    int totalWays(int n, vector<int>capacity) {
        // code here
        long long mod=1e9+7;
        int n1=capacity.size();
        long long sum=1;
        sort(capacity.begin(), capacity.end());
        for(int i=0;i<n1;i++){
            capacity[i]=capacity[i]-i;
            sum=(sum*capacity[i])%mod;
        }
        return sum%mod;
    }
};
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>capacity(n);
		for(int i = 0; i < n; i++)
			cin >> capacity[i];
		Solution ob;
		int ans = ob.totalWays(n, capacity);
		cout << ans << "\n";
	}  
	return 0;
}