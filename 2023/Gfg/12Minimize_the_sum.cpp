// You are given N elements, you can remove any two elements from the list, note their sum, and add the sum to the list. Repeat these steps while there is more than a single element in the list. The task is to minimize the sum of these chosen sums.

 

// Example 1:

// Input:
// N = 4
// arr[] = {1, 4, 7, 10}

// Output:
// 39

// Explanation:
// Choose 1 and 4, Sum = 1 + 4 = 5.
// arr[] = {5, 7, 10} 
// Choose 5 and 7, Sum = 5 + (5 + 7) = 17.
// arr[] = {12, 10} 
// Choose 12 and 10, Sum = 17 + (12 + 10) = 39.
// arr[] = {22}
 

// Example 2:

// Input:
// N = 5
// arr[] = {1, 3, 7, 5, 6}

// Output:
// 48
 

// Your Task:

// You don't need to read input or print anything. The task is to complete the function minimizeSum() which takes N as size of arr array and a arr array. Your task is to minimize the sum of these chosen sums and return it.

 

// Expected Time Complexity: O(N * log(N))
// Expected Auxiliary Space: O(N)

 

// Constraints:

// 1 <= N, arr[i] <= 105

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
   int minimizeSum(int N, vector<int> arr) {
        int sum=0;
        multiset<int>st;
        for(auto i:arr){
            st.insert(i);
        }
        while(!st.empty()){
            if(st.size()==1)break;
            int a=*st.begin();
            st.erase(st.begin());
            int b=*st.begin();
            st.erase(st.begin());
            sum+=(a+b);
            st.insert(a+b);
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends