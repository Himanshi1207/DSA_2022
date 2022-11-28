// Find out the maximum sub-array of non negative numbers from an array.

// The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

// Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

// Example:
// a = [1, 2, 5, -7, 2, 3]
// The two sub-arrays are [1, 2, 5] [2, 3].
// The answer is [1, 2, 5] as its sum is larger than [2, 3]

// NOTE: If there is a tie, then compare with segment's length and return segment which has maximum length.
// If there is still a tie, then return the segment with minimum starting index.
// If no such subarray is present return "-1"

// Example 1:

// Input:
// n = 3
// a[] = {1, 2, 3}
// Output: 1 2 3
// Explanation: In the given array every
// element is non-negative.

#include <bits/stdc++.h>

using namespace std;
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    vector<int> ans;
	    
	    int start=0, end=-1, sum=0, j=0,i=0, maxi=0;
	    while(j<n){
	        if(a[j]>=0){
	            sum+=a[j];
	            j++;
	        }
	        else{
	            if(sum>maxi){
    	            maxi=sum;
    	            start=i;
    	            end=j-1; 
	            }
	            sum=0;
	            j++;
	            i=j;
	        }
	    }
	    if(maxi<sum){
	        maxi=sum;
	        start=i;
	        end=j-1;
	    }
	    for(int i=start;i<=end;i++){
	        ans.push_back(a[i]);
	    }
	    if(ans.empty())
	        ans.push_back(-1);
	    
	    return ans;
	}
};

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}