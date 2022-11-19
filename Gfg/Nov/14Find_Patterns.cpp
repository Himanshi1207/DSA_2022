// Given two strings S and W. Find the number of times W appears as a subsequence of string S where every character of string S can be included in forming at most one subsequence.
 

// Example 1:

// Input: 
//  S = "abcdrtbwerrcokokokd" 
//  W = "bcd" 
// Output: 
//  2
// Explanation: 
// The two subsequences of string W are
// { S1 , S2 , S3 } and { S6 , S11 , S18 }
// (Assuming 0- based indexing).


#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    int numberOfSubsequences(string s, string w){
        // code here 
        int k;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==w[0]){
                k=0;
                for(int j=i;j<s.size() and k<w.size();j++){
                    if(s[j]==w[k]){
                    s[j]='@';
                    k++;
                    }
                }
                if(k==w.size())
                    ans++;
            }
        }
        return ans;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 

