// N Students of different heights are attending an assembly. The heights of the students are represented by an array H[]. The problem is that if a student has less or equal height than the student standing in front of him, then he/she cannot see the assembly. Find the minimum number of students to be removed such that maximum possible number of students can see the assembly.
 

// Example 1:

// Input:
// N = 6
// H[] = {9, 1, 2, 3, 1, 5}
// Output:
// 2
// Explanation:
// We can remove the students at 0 and 4th index.
// which will leave the students with heights
// 1,2,3, and 5.
// Example 2:
// Input:
// N = 3
// H[] = {1, 2, 3} 
// Output :
// 0
// Explanation:
// All of the students are able to see the
// assembly without removing anyone.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int h[], int n) {
        // code here
        vector<int> dp;w
    for(int i=0;i<n;i++){
        int x=h[i];
        auto it=lower_bound(dp.begin(), dp.end(),x);
        if(it==dp.end())
        dp.push_back(x);
        else
        *it=x;
    }
    return n-dp.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends