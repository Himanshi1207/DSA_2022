// You are given an array consisting of n integers which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.
// The first line of input contains two space-separated integers n and k.
// The second line contains n space-separated integers denoting the position of the stalls.

// Example 1:

// Input:
// n=5 
// k=3
// stalls = [1 2 4 8 9]
// Output:
// 3
// Explanation:
// The first cow can be placed at stalls[0], 
// the second cow can be placed at stalls[2] and 
// the third cow can be placed at stalls[3]. 
// The minimum distance between cows, in this case, is 3, 
// which also is the largest among all possible ways.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(int n, int k, vector<int> &stalls) {

        sort(stalls.begin(),stalls.end());

        int l = 0, r = stalls[n-1] - stalls[0];

        int ans = 0;

        while(l <= r){

            int mid = (l + r) / 2;

            int cow = 1;

            int last = stalls[0];

            for(int i = 1;i < n;i++){

                if(stalls[i] - last >= mid){

                   cow++;

                    last = stalls[i];

                }

            }

            if(cow >= k){

                ans = mid;

                l = mid+1;

            }

            else{

                r = mid-1;

            }

        }

        return ans;

 

    }
};

int main() {
    int t = 1;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;
   }
 
    return 0;
}