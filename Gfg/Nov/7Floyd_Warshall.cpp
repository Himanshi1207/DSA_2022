// The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge from i to j. If Matrix[i][j]=-1, it means there is no edge from i to j.
// Do it in-place.

// Example 1:

// Input: matrix = {{0,25},{-1,0}}

// Output: {{0,25},{-1,0}}

// Explanation: The shortest distance between
// every pair is already given(if it exists).



#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	   
	    int n = matrix.size();
	    for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                if(i==k || j==k || matrix[i][k]==-1 || matrix[k][j]==-1)  // skip if k is unreachable from i or j is unreachable from k
	                    continue;
	                else if(matrix[i][j] == -1 )
	                   matrix[i][j] = INT_MAX;
	                matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]);
	            }
	        }
	    }
 	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}