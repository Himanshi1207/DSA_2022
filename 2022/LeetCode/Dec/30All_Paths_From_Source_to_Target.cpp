// Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

// The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

 

// Example 1:


// Input: graph = [[1,2],[3],[3],[]]
// Output: [[0,1,3],[0,2,3]]
// Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
// Example 2:


// Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
// Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void helper(vector<vector<int>>& graph,int node,vector<int> &ds,vector<vector<int>> &ans){
        ds.push_back(node);  
        for(int x: graph[node]){   
            if(x==graph.size()-1){  
                ds.push_back(x);  
                ans.push_back(ds);
                ds.pop_back();   
            }
			
            helper(graph,x,ds,ans);    
            ds.pop_back();    
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> ds;
        helper(graph,0,ds,ans); 
        return ans;
    }
};