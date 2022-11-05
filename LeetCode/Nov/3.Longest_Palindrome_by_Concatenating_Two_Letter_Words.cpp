// You are given an array of strings words. Each element of words consists of two lowercase English letters.

// Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

// Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

// A palindrome is a string that reads the same forward and backward.

 

// Example 1:

// Input: words = ["lc","cl","gg"]
// Output: 6
// Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
// Note that "clgglc" is another longest palindrome that can be created.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int count[26][26] = {};
        int ans = 0;
        
        for (auto w : words) {
            int a = w[0] - 'a';
            int b = w[1] - 'a';
            
            if (count[b][a]) {
                ans += 4;
                count[b][a]--; // decrement the count as we found mirror word
            } else {
                count[a][b]++; // increment the current word if we not find any mirror
            }
        }
        
        for (int i = 0; i < 26; i++) {
            if (count[i][i]) {  // Both are same characters
                ans += 2;
                break;
            }
        }
        return ans;
    }
};
int main(){
    return 0;
}