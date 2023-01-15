// Given a binary string S consists only of 0s and 1s. The task is to calculate the number of substrings that have more 1s than 0s.

// Example 1:

// Input:
// S = "011"
// Output: 4
// Explanation: There are 4 substring which 
// has more 1s than 0s. i.e "011","1","11" and "1"
// Example 2:

// Input:
// S = "0000"
// Output: 0
// Explanation: There is no substring
// which has more 1s than 0s
// Your Task:  
// You dont need to read input or print anything. Complete the function countSubstring() which takes the string S as input parameter and returns the number of substring which has more 1s than 0s.

// Expected Time Complexity: O(|S|)
// Expected Auxiliary Space: O(|S|)

// Constraints:
// 1 < |S| < 105
// |S| denotes the length of the string S

//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
  long long countSubstring(string s){
    // start writing from here
    long long ans=0;
    unordered_map<long long,long long> help; // start unodering     
    vector<long long> dp(s.size(),0); // define the vector size
    long long sum=-1;
    if(s[0]=='1'){
         dp[0]=1;
         ans=1;
         sum=1;
    }
    help[sum]=0;
    help[0]=-1;
    for(int i=1;i<s.size();i++){
        long long temp=0;
        if(s[i]=='0')
            sum-=1;
        else
            sum+=1;
        if(s[i]=='0'){
            if(help.find(sum)!=help.end()) {
                if(help[sum]!=-1){
                    temp+=dp[help[sum]];
                }
            }
        }
        else{
            if(help.find(sum)!=help.end()){
                if(help[sum]!=-1){
                    temp=dp[help[sum]]+i-help[sum]-1;
                }
                else{
                    temp=i-help[sum]-1;
                }
            }
            else{
                temp+=i+1;
            }
        }
        help[sum]=i;
        dp[i]=temp;
        ans+=temp;
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 int t=1;
 cin>>t;
 for(int i=1;i<=t;i++){
    string S;
    cin>>S;
    Solution obj;
    long long ans =obj.countSubstring(S);
    cout<<ans<<endl;
 }
}
// } Driver Code Ends