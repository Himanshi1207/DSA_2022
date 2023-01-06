// You are given two four digit prime numbers Num1 and Num2. Find the distance of the shortest path from Num1 to Num2 that can be attained by altering only one single digit at a time. Every number obtained after changing a digit should be a four digit prime number with no leading zeros.


// Example 1:

// Input:
// Num1 = 1033 
// Num2 = 8179
// Output: 6
// Explanation:
// 1033 -> 1733 -> 3733 -> 3739 -> 3779
//                  -> 8779 -> 8179.
// There are only 6 steps required to reach
// Num2 from Num1, and all the intermediate
// numbers are 4 digit prime numbers.
// Example 2:

// Input:
// Num1 = 1033 
// Num2 = 1033
// Output:
// 0

//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    int shortestPath(int num1,int num2){   

        // Complete this function using prime vector

        vector<int>prime(10000,1);

        prime[1]=0;

        for(int i=2;i*i<=9999;i++){

            if(prime[i]){

                for(int j=i*i;j<=9999;j+=i)

                    prime[j]=0;

            }

        }

        vector<int>vis(10000,-1);

        queue<int>q;

        q.push(num1);

        vis[num1]=0;

        while(!q.empty()){

         int t=q.front();

         q.pop();

         string s=to_string(t);

     for(int i=0;i<s.length();i++){

     char ch=s[i];

     for(int j=(i==0?1:0);j<=9;j++){

     s[i]=j+'0';

     if(prime[stoi(s)] && vis[stoi(s)]==-1){

     vis[stoi(s)]=1+vis[t];

     q.push(stoi(s));

     }

     }

     s[i]=ch;

     }

     }

        return vis[num2];

    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends