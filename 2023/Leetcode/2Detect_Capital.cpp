// We define the usage of capitals in a word to be right when one of the following cases holds:

// All letters in this word are capitals, like "USA".
// All letters in this word are not capitals, like "leetcode".
// Only the first letter in this word is capital, like "Google".
// Given a string word, return true if the usage of capitals in it is right.

 

// Example 1:

// Input: word = "USA"
// Output: true
// Example 2:

// Input: word = "FlaG"
// Output: false
 

// Constraints:

// 1 <= word.length <= 100
// word consists of lowercase and uppercase English letters.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size()==1)
            return true;
        bool first=false;
        if(word[0]>='A' and word[0]<='Z'){
            first=true;
        }
        
        int cap=0, small=0;
        if(first)
            cap++;
        else
            small++;
        for(int i=1;i<word.size();i++){
            if(word[i]>='a' and word[i]<='z')
                small++;
            else
                cap++;
        }
        int sz=word.size();
        cout<<small<<endl;
        if(small==sz or cap==sz or (first and small==sz-1))
            return true;
        return false;
    }
};