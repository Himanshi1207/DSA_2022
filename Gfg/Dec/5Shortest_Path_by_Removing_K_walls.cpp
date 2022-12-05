// Given a 2-D binary matrix of size n*m, where 0 represents an empty space while 1 represents a wall you cannot walk through. You are also given an integer k.
// You can walk up, down, left, or right. Given that you can remove up to k walls, return the minimum number of steps to walk from the top left corner (0, 0) to the bottom right corner (n-1, m-1).
// Note: If there is no way to walk from the top left corner to the bottom right corner, return -1.


// Example 1:

// Input: n = 3, m = 3, k = 1
// mat = {{0, 0, 0},
//        {0, 0, 1},
//        {0, 1, 0}}
// Output:
// 4
// Explanation:
// We can remove any one of the walls and
// reach the bottom in 4 moves.  

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int shotestPath(vector<vector<int>> grid, int m, int n, int k) {
        // code here
        vector<vector<int>> visited(m, vector<int>(n, -1));
        queue<vector<int>> q;
        q.push({0,0,0,k});
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            int x=t[0], y=t[1];
            if(x<0 or x>=m or y<0 or y>=n)
                continue;
            if(x==m-1 and y==n-1)
                return t[2];
            if(grid[x][y]==1){
                if(t[3]>0)
                    t[3]--;
                else
                    continue;
            }
            if(visited[x][y]!=-1 and visited[x][y]>=t[3]){
                continue;
            }
            visited[x][y]=t[3];
            q.push({x+1,y,t[2]+1,t[3]});
            q.push({x-1,y,t[2]+1,t[3]});
            q.push({x,y+1,t[2]+1,t[3]});
            q.push({x,y-1,t[2]+1,t[3]});
        }
        return -1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}