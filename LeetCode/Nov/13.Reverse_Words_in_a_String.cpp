// Given an input string s, reverse the order of the words.

// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

// Return a string of the words in reverse order concatenated by a single space.

// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

// Example 1:

// Input: s = "the sky is blue"
// Output: "blue is sky the"
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
         stack<string>st;
        for(int i =0;i<s.length();i++){
            string word=""; 
            if(s[i]==' ')continue;
            while(s[i]!=' ' and i<s.length()){
                word+=s[i];
                i++;
            }
            st.push(word);
           
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
            if(!st.empty())ans+=" ";
        }
        
        return ans;

    }
};