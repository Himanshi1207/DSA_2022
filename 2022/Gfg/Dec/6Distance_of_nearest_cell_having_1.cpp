// Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
// The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1.
 

// Example 1:

// Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
// Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}
// Explanation: The grid is-
// 0 1 1 0 
// 1 1 0 0 
// 0 0 1 1 
// 0's at (0,0), (0,3), (1,2), (1,3), (2,0) and
// (2,1) are at a distance of 1 from 1's at (0,1),
// (0,2), (0,2), (2,3), (1,0) and (1,1)
// respectively.

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	int n , m;
    public:
    bool check( int i , int j){
        return(!(i < 0 || i >= n || j < 0 || j >= m));
    }
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    n = grid.size();
	    m = grid[0].size();
	    vector<vector<int>>result(n , vector<int> (m , INT_MAX));
	    int total = n * m;
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < m; j++){
	            if(grid[i][j] == 1){
	                result[i][j] = 0;
	                total --;
	            }
	        }
	    }
	    if(total == 0)
	        return result;
	    int curr = 0;
	    while(total != 0){
	        for(int i = 0; i < n; i++){
	            for(int j = 0; j < m; j++){
	                
	                if(result[i][j] == curr){
	                    if(check (i - 1 , j) && result[i - 1][j] == INT_MAX){
	                        result[i - 1][j] = curr + 1;
	                        total --;
	                    }
	                    if(check (i + 1 , j) && result[i + 1][j] == INT_MAX){
	                        result[i + 1][j] = curr + 1;
	                        total --;
	                    }
	                    if(check (i , j -1) && result[i][j - 1] == INT_MAX){
	                        result[i][j - 1] = curr + 1;
	                        total --;
	                    }
	                    if(check (i, j + 1) && result[i][j + 1] == INT_MAX){
	                        result[i][j + 1] = curr + 1;
	                        total --;
	                    }
	                }
	            }
	        }
	        curr ++;
	    }
	    return result;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}