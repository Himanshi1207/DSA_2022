// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

 

// Example 1:

// Input: text1 = "abcde", text2 = "ace" 
// Output: 3  
// Explanation: The longest common subsequence is "ace" and its length is 3.
// Example 2:

// Input: text1 = "abc", text2 = "abc"
// Output: 3
// Explanation: The longest common subsequence is "abc" and its length is 3.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int t1=text1.size();
        int t2=text2.size();
        vector<vector<int>> dp(t1+1, vector<int> (t2+1,0));
        for(int i=1;i<=t1;i++){
            for(int j=1;j<=t2;j++){
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=max(dp[i][j], dp[i-1][j-1]+1);
            }
        }
        return dp[t1][t2];
    }
};