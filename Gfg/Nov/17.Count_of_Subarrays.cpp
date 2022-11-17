
// Given an array of N positive integers  Arr1, Arr2 ............ Arrn. The value of each contiguous subarray of given array is the maximum element present in that subarray. The task is to return the number of subarrays having value strictly greater than K.

// Example 1:

// Input:
// N = 3, K = 2
// Arr[] = {3, 2, 1}
// Output: 3
// Explanation: The subarrays having value
// strictly greater than K are: [3], [3, 2]
// and [3, 2, 1]. Thus there are 3 such
// subarrays.


#include <bits/stdc++.h>

using namespace std;

#define ll long long


class Solution{
public:

	ll countSubarray(int arr[], int n, int k) {
	    // code here
	     ll  count=0;

  ll  temp=0;

     for(int i=0;i<n;i++)

     {

         if(arr[i]<=k)

          {

              count++;

              temp+=count;

              

          }

          else 

          count=0;

     }

   ll  ans=(ll)n*(n+1)/2;

     ans=(ll)(ans-temp);

     return ans;
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countSubarray(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}