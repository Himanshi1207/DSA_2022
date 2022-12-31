// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique, or false otherwise.

 

// Example 1:

// Input: arr = [1,2,2,1,1,3]
// Output: true
// Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // return true;
        int n=arr.size();
        unordered_map<int, int> freq;
        set<int> st;
        cout<<n<<endl;
        for(int i=0;i<n;i++){
            // cout<<"freq";
            freq[arr[i]]++;
        }
        for(auto it: freq){
            // cout<<"enter";
            int ss=st.size();
            st.insert(it.second);
            // cout<<it.second<<" "<<endl;
            if(st.size()!=(ss+1))
                return false;
        }
        return true;
    }
};