// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

// Return the sorted string. If there are multiple answers, return any of them.

 

// Example 1:

// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freqs;
        priority_queue<pair<int,char>> maxheap;
        for(int i=0;i<s.size();i++)
            freqs[s[i]]++;
        for(auto it: freqs)
            maxheap.push({it.second, it.first});
        s="";
        while(!maxheap.empty()){
            s+=string(maxheap.top().first, maxheap.top().second);
            maxheap.pop();
        }
        return s;
    }
};