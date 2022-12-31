// Given a really large number N, break it into 3 whole numbers such that they sum up to the original number and find the number of ways to do so. Since this number can be very large, return it modulo 109+7. 

 

// Example 1:

// Input:
// N = 2
// Output:
// 6
// Explanation:
// Possible ways to break the number:
// 0 + 0 + 2 = 2 
// 0 + 2 + 0 = 2
// 2 + 0 + 0 = 2
// 0 + 1 + 1 = 2
// 1 + 1 + 0 = 2
// 1 + 0 + 1 = 2
 

 

// Example 2:

// Input:
// N = 3
// Output:
// 10
// Explanation:
// Possible ways to break the number:
// 0+0+3 = 3
// 0+3+0 = 3
// 3+0+0 = 3
// 0+1+2 = 3
// 0+2+1 = 3
// 1+0+2 = 3
// 1+2+0 = 3
// 2+0+1 = 3
// 2+1+0 = 3
// 1+1+1 = 3

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    int waysToBreakNumber(int n){
        // code here 
        long long int mod=1e9+7;
        return ((((n+1)%mod)*((n+2)%mod))/2)%mod;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.waysToBreakNumber(N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends