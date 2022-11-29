// Given an array arr[] of n integers, where each integer is greater than 1. The task is to find the number of Full binary tree from the given integers, such that each non-leaf node value is the product of its children value.

// Note: Each integer can be used multiple times in a full binary tree. The answer can be large, return  answer modulo 1000000007

// Example 1:
// Input:
// n = 4
// arr[] = {2, 3, 4, 6}
// Output:
// 7
// Explanation:
// There are 7 full binary tree with
// the given product property.
// Four trees with single nodes
// 2  3  4  6
// Three trees with three nodes
//     4   
//    / \
//   2   2 ,
//    6    
//   / \
//  2   3 ,
//    6
//   / \
//  3   2

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    
    long long int numoffbt(long long int arr[], int n){
        // Your code goes here
        long long int mod=1e9+7;
        long long int mini=INT_MAX, maxi=INT_MIN;
        for(int i=0;i<n;i++){
            mini=min(mini, arr[i]);
            maxi=max(maxi, arr[i]);
        }
        long long int ans=0;
        long long int pd;
        vector<bool> visited(maxi+2, false);
        vector<long long int> solution(maxi+2, 0);
        for(int i=0;i<n;i++){
            visited[arr[i]]=true;
            solution[arr[i]]=1;
        }
        for(int i=mini;i<=maxi;i++){
            if(!visited[i])
                continue;
            for(int j=2; i*j<=maxi and j<=i; j++){
                pd=i*j;
                if(!visited[pd])
                    continue;
                solution[pd]=(solution[pd]+(solution[i]*solution[j])%mod)%mod;
                if(i!=j)
                    solution[pd]=(solution[pd]+(solution[i]*solution[j])%mod)%mod;
            }
            ans=(ans+solution[i])%mod;
        }
        return ans;
    }
};

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<<ob.numoffbt(a,n)<<endl;
		
	}
	return 0;
}