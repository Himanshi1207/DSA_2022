// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

// A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

// Example 1:


// Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
// Output: 13
// Explanation: There are two falling paths with a minimum sum as shown.
// Example 2:


// Input: matrix = [[-19,57],[-40,-5]]
// Output: -59
// Explanation: The falling path with a minimum sum is shown.

#include<bits/stdc++.h>
using namespace std;
const int N=100;
int dp[N+1][N+1];
class Solution {
public:
    int helper(int i, int j, vector<vector<int>> matrix){
        if(i<0 or j>=matrix[0].size())
            return 1e9;
        if(i==0)
            return matrix[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int u=matrix[i][j]+helper(i-1,j,matrix);
        int ul=matrix[i][j]+helper(i-1,j-1,matrix);
        int ur=matrix[i][j]+helper(i-1,j+1,matrix);
        return dp[i][j]= min(u,min(ul,ur));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof(dp));
        int ans=INT_MAX;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0)
                    dp[i][j]=matrix[i][j];
                else{
                    int u=matrix[i][j]+dp[i-1][j];
                    int ul=matrix[i][j];
                        if(j-1>=0)
                            ul+=dp[i-1][j-1];
                    else
                        ul+=1e8;
                    int ur=matrix[i][j];
                        if(j+1<m)
                            ur+=dp[i-1][j+1];
                    else
                        ur+=1e8;
                    dp[i][j]=min(u, min(ul,ur));
                }
            }
        }
        for(int j=0;j<m;j++){
            ans=min(ans, dp[n-1][j]);
        }
        return ans;
    }
};