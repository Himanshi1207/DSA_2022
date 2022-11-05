// Given a string s, reverse only all the vowels in the string and return it.

// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

// Example 1:

// Input: s = "hello"
// Output: "holle"



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        string rev;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u' or s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U')
                rev.push_back(s[i]);
        }
        reverse(rev.begin(), rev.end());
        int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u' or s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U'){
                s[i]=rev[j++];
            }
        }
        return s;
    }
};
int main(){
    Solution obj;
    string s;
    cin>>s;
    cout<<obj.reverseVowels(s);
    return 0;
}
