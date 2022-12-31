// Two strings are considered close if you can attain one from the other using the following operations:

// Operation 1: Swap any two existing characters.
// For example, abcde -> aecdb
// Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
// For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
// You can use the operations on either string as many times as necessary.

// Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

 

// Example 1:

// Input: word1 = "abc", word2 = "bca"
// Output: true
// Explanation: You can attain word2 from word1 in 2 operations.
// Apply Operation 1: "abc" -> "acb"
// Apply Operation 1: "acb" -> "bca"

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size())
            return false;
        unordered_set<int> st;
        vector<int> freq1(26,0), freq2(26,0);
        for(int i=0;i<word1.size();i++){
            freq1[word1[i]-'a']++;
            st.insert(word1[i]);
        }
        for(int i=0;i<word2.size();i++){
            if(st.find(word2[i])==st.end())
                return false;
            freq2[word2[i]-'a']++;
        }
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        if(freq1==freq2)
            return true;
        return false;
    }
};