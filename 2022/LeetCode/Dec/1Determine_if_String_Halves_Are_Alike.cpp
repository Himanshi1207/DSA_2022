// You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

// Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

// Return true if a and b are alike. Otherwise, return false.

 

// Example 1:

// Input: s = "book"
// Output: true
// Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.size();
        int first=0, second=0;
        int i=0,j=n/2;
        for(i=0,j=n/2;i<n/2 and j<n;i++,j++){
            if(s[i]=='A' or s[i]=='a' or s[i]=='E' or s[i]=='e' or s[i]=='I' or s[i]=='i' or s[i]=='O' or s[i]=='o' or s[i]=='U' or s[i]=='u'){
                first++;
            }
            if(s[j]=='U' or s[j]=='O' or s[j]=='I' or s[j]=='E' or s[j]=='A' or s[j]=='o' or s[j]=='a' or s[j]=='i' or s[j]=='e' or s[j]=='u'){
                second++;
            }
        }
        cout<<i<<" "<<j<<endl;
        if(first!=second)
            return false;
        return true;
    }
};