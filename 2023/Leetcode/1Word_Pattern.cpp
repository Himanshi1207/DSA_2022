// tag-EASY
// Link-https://leetcode.com/problems/word-pattern/
//  Given a pattern and a string s, find if s follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

// Example 1:

// Input: pattern = "abba", s = "dog cat cat dog"
// Output: true
// Example 2:

// Input: pattern = "abba", s = "dog cat cat fish"
// Output: false
// Example 3:

// Input: pattern = "aaaa", s = "dog cat cat dog"
// Output: false
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        unordered_map<char, string>chToWordMap;
        unordered_map<string, char>wordToChMap;
        s.push_back(' ');
        string currWord = "";
        int chIdx = 0;
        
        for (int  i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ') 
            {
                char currCh = pattern[chIdx++];
                
                if (chToWordMap.count(currCh))
                {
                    string alreadyMappedWord = chToWordMap[currCh];
                    if (alreadyMappedWord != currWord) return false;
                }
                else if (wordToChMap.count(currWord))
                {
                    char alreadyMappedCh = wordToChMap[currWord];
                    if (alreadyMappedCh != currCh) return false;
                }
                else
                {
                    chToWordMap[currCh] = currWord;
                    wordToChMap[currWord] = currCh;
                }
                
                currWord = "";
            }
            else currWord.push_back(s[i]);
        }
        
        return (chIdx == pattern.size());
        
    }
};