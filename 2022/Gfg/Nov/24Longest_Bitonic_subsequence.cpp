// Given an array of positive integers. Find the maximum length of Bitonic subsequence. 
// A subsequence of array is called Bitonic if it is first strictly increasing, then strictly decreasing.
 

// Example 1:

// Input: nums = [1, 2, 5, 3, 2]
// Output: 5
// Explanation: The sequence {1, 2, 5} is
// increasing and the sequence {3, 2} is 
// decreasing so merging both we will get 
// length 5.


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	int LongestBitonicSequence(vector<int> arr) {
        // code here
        int cur = 0, res = 0;
        int n = arr.size();
        vector<int> left(n), right(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++)
                if (arr[j] < arr[i])
                    left[i] = max(left[i], left[j] + 1);
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--)
                if (arr[j] < arr[i])
                    right[i] = max(right[i], right[j] + 1);
        }
        for (int i = 0; i < n; i++)
            res = max(res, left[i] + right[i] + 1);
        return res;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}