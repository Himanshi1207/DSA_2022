// You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at.

// In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find the nearest exit from the entrance. An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.

// Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.

 

// Example 1:


// Input: maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance = [1,2]
// Output: 1
// Explanation: There are 3 exits in this maze at [1,0], [0,2], and [2,3].
// Initially, you are at the entrance cell [1,2].
// - You can reach [1,0] by moving 2 steps left.
// - You can reach [0,2] by moving 1 step up.
// It is impossible to reach [2,3] from the entrance.
// Thus, the nearest exit is [0,2], which is 1 step away.


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int m,n;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    bool isBorder(int i,int j){
        return (i==0 || i==m-1 || j == 0 || j == n-1);
    }
    
    bool valid(int r,int c){
        return (r>=0 && c>=0 && r<m && c<n);
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& ent) {
        m = maze.size() , n=maze[0].size();
        if(isBorder(ent[0] , ent[1]))  
            maze[ent[0]][ent[1]] = '+';
        int ans = 0;
        queue<pair<int,int>> q;
        q.push({ent[0],ent[1]});
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto top = q.front();
                q.pop();
                int x = top.first , y = top.second;
                if(maze[x][y] != '+' && isBorder(x,y))
                    return ans;
                for(int j=0;j<4;j++){
                    int r = x + dx[j];
                    int c = y + dy[j];
                    if(valid(r,c) && maze[r][c]=='.'){
                        q.push({r,c});
                        maze[r][c] = '*';
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};