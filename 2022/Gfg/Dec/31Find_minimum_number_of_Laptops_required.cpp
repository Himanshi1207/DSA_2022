// There are N jobs and the start and finish time of the jobs are given in arrays start[] and end[] respectively. Each job requires one laptop and laptops can't be shared. Find the minimum number of laptops required given that you can give your laptop to someone else when you are not doing your job.


// Example 1:

// Input:
// N = 3
// start[] = {1, 2, 3}
// end[] = {4, 4, 6}
// Output:
// 3
// Explanation:
// We can clearly see that everyone's supposed to
// be doing their job at time 3. So, 3 laptops
// will be required at minimum.
// Example 2:

// Input:
// N = 3
// start[] = {1, 5, 2}
// end[] = {2, 6, 3}
// Output :
// 1
// Explanation:
// All jobs can be done using 1 laptop only.
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minLaptops(int N, int start[], int end[]) {
        // Code here
        map<int,int> laptops;
        for(int i=0;i<N;i++){
            laptops[start[i]]++;
            laptops[end[i]]--;
        }
        vector<pair<int,int>> vec;
        for(auto it: laptops)
            vec.push_back(it);
            int c=0,ans=0;
        for(auto it:vec){
            c+=it.second;
            ans=max(ans, c);
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}