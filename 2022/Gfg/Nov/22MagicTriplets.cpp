// Given an array of size n, a triplet (a[i], a[j], a[k]) is called a Magic Triplet if a[i] < a[j] < a[k] and i < j < k.  Count the number of magic triplets in a given array.
 

// Example 1:

// Input: arr = [3, 2, 1]
// Output: 0
// Explanation: There is no magic triplet..

#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	int countTriplets(vector<int>nums){
	    int ans=0;
	    for(int i=1;i<nums.size()-1;i++){
	        int left=0, right=0;
	        for(int j=0;j<i;j++){
	            if(nums[j]<nums[i])
	                left++;
	        }
	        for(int k=i+1;k<nums.size();k++){
	            if(nums[k]>nums[i])
	                right++;
	        }
	        ans=ans+(left*right);
	    }
	    return ans;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}