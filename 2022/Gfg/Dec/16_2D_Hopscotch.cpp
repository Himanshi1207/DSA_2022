// Aakriti, Avantika and Mehak are playing 2D Hopscotch. The arena is in the form of a n*m 2D matrix. But the position of the cells is slightly modified as shown below. 


// Mehak starts the game from tile (i,j) while Avantika and Aakriti direct her. In each turn Mehak will collect all the stones present (1 or 2) steps away from where she is standing. Avantika can direct Mehak to take 1 step and and Aakriti can direct Mehak to take 2 steps. 
// If the director ty is known to you as ty = 0 being Avantika and 1 being Aakriti, find the number of stones that Mehak will collect. 


// Example 1:

// Input: 
// n = 3, m = 3
// mat = {{5, 9, 7}, 
//        {6, 4, 5}, 
//        {8, 1, 2}}
// ty = 0, 
// i = 1, j = 1
// Output: 31
// Explaination: 
// ty=0, so Avantika is the director. 
// ie- Mehak will move only one step in 
// any direction to collect the stones.
// (0,1), (1,0), (1,2), (2,1), (2,2), (2,0) 
// are at a distance of 1 from (1,1). 
// Adding them 9+6+5+8+1+2=31.

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int hopscotch(int n, int m, vector<vector<int>> mat, int ty, int i, int j)
    {
        // code here
        int ans=0, t=-pow(-1,(j&1));
        vector<vector<int>> dx={{0,-1,0,1,t,t},{0,-2,0,2,-1,-1,1,1,-t,-t,2*t,2*t}};
        vector<vector<int>> dy={{-1,0,1,0,-1,1},{-2,0,2,0,-2,2,-2,2,-1,1,-1,1}};
        
        for(int k=0;k<6*(ty+1);k++){
            int x=i+dx[ty][k],y=j+dy[ty][k];
            if(x>=0 and x<n and y>=0 and y<m)
                ans+=mat[x][y];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>ty>>i>>j;
        
        Solution ob;
        cout<<ob.hopscotch(n, m, mat, ty, i, j)<<"\n";
    }
    return 0;
}
// } Driver Code Ends