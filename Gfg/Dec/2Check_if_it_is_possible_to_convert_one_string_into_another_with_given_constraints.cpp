// Given two strings S and T, which contains three characters i.e 'A', 'B' and '#' only. Check whether it is possible to convert the first string into another string by performing following operations on string first.
// 1- A can move towards Left only
// 2- B can move towards Right only
// 3- Neither A nor B should cross each other
// Note: Moving i'th character towards Left one step means swap i'th with (i-1)'th charecter [ i-1>=0 ]. Moving i'th character towards Right one step means swap i'th with (i+1)'th charecter [ i+1< string's length ]. 

// Example 1:

// Input:
// S=#A#B#B#   
// T=A###B#B
// Output:
// 1
// Explanation:
// A in S is right to the A in T 
// so A of S can move easily towards
// the left because there is no B on
// its left positions and for first B 
// in S is left to the B in T so B 
// of T can move easily towards the 
// right because there is no A on its
// right positions and it is same for 
// next B so S can be easily converted
// into T.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int isItPossible(string s, string t, int m, int n) {
        // code here
        int i=0, j=0;
        while(i<m and j<n){
            while(i<m and s[i]=='#')
                i++;
            while(j<n and t[j]=='#')
                j++;
            if(s[i]!=t[j])
                return false;
            if(s[i]=='A' and i<j)
                return false;
            if(t[j]=='B' and j<i)
                return false;
            i++;
            j++;
        }
        return true;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}