// Given an array arr[] of N elements and a number K. Split the given array into K subarrays such that the maximum subarray sum achievable out of K subarrays formed is minimum possible. Find that possible subarray sum.


// Example 1:

// Input:
// N = 4, K = 3
// arr[] = {1, 2, 3, 4}
// Output: 4
// Explanation:
// Optimal Split is {1, 2}, {3}, {4}.
// Maximum sum of all subarrays is 4,
// which is minimum possible for 3 splits. 

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int splitArray(int arr[] ,int N, int K) {
        // code here
         int max=INT_MIN,sum=0;
        for(int i=0;i<N;i++) {
            if(arr[i]>max) {
                max=arr[i];
            }
            sum+=arr[i];
        }
        int ans,l=max,h=sum,mid;
        while(l<=h) {
            mid=(l+h)/2;
            int ctr=1,s=0;
            for(int i=0;i<N;i++) {
                s+=arr[i];
                if(s>mid) {
                    ctr++;
                    s=arr[i];
                }
            }
            if(ctr>K) {
                l=mid+1;
            }
            else {
                ans=mid;
                h=mid-1;
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}