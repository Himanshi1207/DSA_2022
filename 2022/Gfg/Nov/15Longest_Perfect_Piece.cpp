// Given an array arr[] of N Numbers. A Perfect Piece is defined as a subarray such that the difference between the minimum and the maximum value in that range is at most 1. Find the Maximal Length Perfect Piece.

 

// Example 1:

// Input:
// N = 4
// arr[] = {8, 8, 8, 8}
// Output:
// 4
// Explanation:
// The longest subarray is [1, 4]
// where maximum=8 and minimum = 8 and
// difference is 0, which is less than 1.
// Its length is 4.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestPerfectPiece(int arr[], int n) {
        // code here
        int low=0, high=0, ans=0;
        map<int,int> freq;
        while(high<n){
            freq[arr[high]]++;
            while((--freq.end())->first-freq.begin()->first>1){
                freq[arr[low]]--;
                if(freq[arr[low]]==0)
                    freq.erase(arr[low]);
                low++;
            }
            ans=max(ans, high-low+1);
            high++;
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}