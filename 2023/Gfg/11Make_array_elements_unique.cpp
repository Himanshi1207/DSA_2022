// Given an array arr[ ] of N elements, your task is to find the minimum number of increment operations required to make all the elements of the array unique. ie- no value in the array should occur more than once. In an operation a value can be incremented by 1 only.

// Example 1:

// Input:
// N = 3
// arr[] = {1, 2, 2}
// Output:
// 1
// Explanation:
// If we increase arr[2] by 1 then the resulting 
// array becomes {1, 2, 3} and has all unique values.
// Hence, the answer is 1 in this case.
// Example 2:

// Input: 
// N = 4
// arr[] = {1, 1, 2, 3}
// Output:
// 3
// Explanation: 
// If we increase arr[0] by 3, then all array
// elements will be unique. Hence, the answer 
// is 3 in this case.
// Your Task:
// You dont need to read input or print anything. Complete the function minIncrements() which takes the array arr[ ] and its size N as the input parameters, and returns the minimum increment operations required to make all elements of the array unique.

// Expected Time Complexity: O(N*log(N))
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 105 
// 1 ≤ arr[i] ≤ 109

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        // Code here
        unordered_map<int,int> mp;
        long long int ans=0;
        for(int i=0;i<N;i++){
            if(mp.find(arr[i])==mp.end()){
                mp[arr[i]]=1;
            }
            else{
                while(mp.find(arr[i])!=mp.end()){
                    ans++;
                    arr[i]++;
                }
                mp[arr[i]]=1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends