// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

 

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]
 

// Constraints:

// 1 <= s.length <= 16
// s contains only lowercase English letters.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(int idx, string s, vector<vector<string>> &ans, vector<string> &temp){
        if(idx==s.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(isPalindrome(s,idx,i)){
                temp.push_back(s.substr(idx,i-idx+1));
                solve(i+1,s,ans,temp);
                temp.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0, s, ans, temp);
        return ans;
    }
};