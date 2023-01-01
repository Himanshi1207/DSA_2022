// Given a number n, find count of all binary sequences of length 2n such that sum of first n bits is same as sum of last n bits.
// The anwer can be very large. So, you have to return answer modulo 109+7.

// Example:

// Input: n = 2
// Output: 6
// Explanation: There are 6 sequences of length 
// 2*n, the sequences are 0101, 0110, 1010, 1001, 
// 0000 and 1111.
// Example:

// Input: n = 1
// Output: 2
// Explanation: There are 2 sequence of length 
// 2*n, the sequence are 00 and 11.
 

// Your Task:
// You don't need to read or print anyhting. Your task is to complete the function compute_value() which takes n as input parameter and returns count of all binary sequence of length 2*n such that sum of first n bits is same as sum of last n bits modulo 109 + 7.
 

// Expected Time Complexity: O(n * log(n))
// Expected Space Complexity:  O(1)

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#define ll long long int
class Solution{
	public:
	ll mod = 1000000007;
	int compute_value(int n)
	{
	    // Code here
	    vector<int> fact(n+1,0);
	    fact[0]=1;
        for(int i=1;i<=n;i++) fact[i] = multi(fact[i-1],i);
        
        int ans=0,val=0;
        for(int r=0;r<=n;r++) {
            val = divide(fact[n],multi(fact[r],fact[n-r]));
            ans = add(ans,multi(val,val));
        }
        
        return ans;
	}
	
	int power(ll a,ll b) {
        if(b==0) return 1;
        int p = power(a,b/2);
        p = multi(p,p);
        if(b%2==1) p = multi(p,a);
        return p;
    }
    
    int add(ll a,ll b) {
        return (int)(((a%mod)+(b%mod))%mod);
    }
    
    int multi(ll a,ll b) {
        return (int)(((a%mod)*(b%mod))%mod);
    }
    
    int divide(ll a,ll b) {
        return multi(a,power(b,mod-2));
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends