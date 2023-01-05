// Given an array of strings arr[]. You have to find the longest string which is lexicographically smallest and also all of its prefix strings are already present in the array.

 

// Example 1:

// Input: ab a abc abd
// Output: abc
// Explanation: We can see that length of the longest 
// string is 3. And there are two string "abc" and "abd"
// of length 3. But for string "abc" , all of its prefix
// "a" "ab" "abc" are present in the array. So the
// output is "abc".
// Example 2:

// Input: ab a aa abd abc abda abdd abde abdab
// Output: abdab
// Explanation: We can see that each string is fulfilling
// the condition. For each string, all of its prefix 
// are present in the array.And "abdab" is the longest
// string among them. So the ouput is "abdab".
 //{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
#include<bits/stdc++.h>
class Solution
{
public:
    string longestString(vector<string> &words)
    {
        // code here
        unordered_map<string, int> mp;
        sort(words.begin(), words.end());
        for(auto it:words){
            mp[it]++;
        }
        string ans="";
        
        for(auto it:words){
            string temp="";
            int cnt=0, n=it.size();
            for(int i=0;i<n;i++){
                temp+=it[i];
                if(mp.find(temp)!=mp.end()){
                    cnt++;
                }
            }
            if(cnt==n and ans.size()<cnt)
            {
                ans=it;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends