// Given a string S, return the sum of beauty of all its substrings.
// The beauty of a string is defined as the difference in frequencies between the most frequent and least frequent characters.

// For example, the beauty of string "aaac" is 3 - 1 = 2.
// Example 1:

// Input:
// S = "aaac"
// Output:
// 3
// Explanation: The substrings with non - zero beauty are ["aaac","aac"] where beauty of "aaac" is 2 and beauty of "aac" is 1.

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
  int beautySum(string s) {
        // Your code goes here
        int ans=0;
        for(int i=0;i<s.length();i++) {
            vector<int> fre(26,0);
            for(int j=i;j<s.length();j++) {
                fre[s[j]-'a']++;
                ans+=findBeauty(fre);
            }
        }
        return ans;
    }
    
    int findBeauty(vector<int> fre) {
        int mx=INT_MIN,mn=INT_MAX;
        for(int f : fre) {
            if(f==0) continue;
            mx = max(mx,f);
            mn = min(mn,f);
        }
        return mx-mn;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}