// Given an unsorted array arr[ ] of size n, you need to find the maximum difference of absolute values of elements and indexes, i.e., for i <= j, calculate maximum of | arr[ i ] - arr[ j ] | + | i - j |. 

// Example 1:

// Input : 
// n = 3
// arr[ ] = {1, 3, -1}
// Output: 5
// Explanation:
// Maximum difference comes from indexes 
// 1, 2 i.e | 3 - (-1) | + | 1 - 2 | = 5

// Example 2:

// Input : 
// n = 4
// arr[ ] = {5, 9, 2, 6} 
// Output:  8
// Explanation: 
// Maximum difference comes from indexes 
// 1, 2 i.e | 9 - 2 | + | 1 - 2 | = 8

#include <bits/stdc++.h> 
using namespace std; 

class Solution{
  public:
    int maxDistance(int arr[], int n) {
        int ans = 0, mn1 = arr[0], mn2 = -arr[0];
        for(int i = 0; i < n; i++) {
            mn1 = min(mn1,  arr[i] + i);
            mn2 = min(mn2, -arr[i] + i);
            ans = max(ans,  arr[i] + i - mn1);
            ans = max(ans, -arr[i] + i - mn2);
        }
        return ans;
    } 
};

int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    Solution obj;
	    cout<<obj.maxDistance(arr, n)<<endl;
	}
} 
