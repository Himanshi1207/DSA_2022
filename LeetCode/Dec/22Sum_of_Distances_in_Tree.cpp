// There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

// You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

// Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes.

 

// Example 1:


// Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
// Output: [8,12,6,10,10,10]
// Explanation: The tree is shown above.
// We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
// equals 1 + 1 + 2 + 2 + 2 = 8.
// Hence, answer[0] = 8, and so on.

#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void dfs1(vector<int> adj[], vector<int>& child, int length, int root, vector<int>& visited,vector<int> &ans){
        visited[root] = 1;
        ans[0] += length;
        length++;
        for(auto& x: adj[root]){
            if(visited[x]) continue;
            dfs1(adj, child, length, x, visited, ans);
            child[root] += child[x];
        }
        child[root] += 1;
    }
    
    void dfs2(vector<int> adj[], vector<int>& child, int root, vector<int>& visited, int n, vector<int>& ans){
        visited[root] = 1;
        for(auto& x: adj[root]){
            if(visited[x]) continue;
            ans[x] = ans[root] - child[x] + n - child[x];
            dfs2(adj , child, x, visited, n, ans);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        vector<int> adj[n];
        for(auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> ans(n), child(n), visited(n);
        dfs1(adj , child, 0, 0, visited, ans);
        for(int i=0;i<n;i++)visited[i]=0;
        
        dfs2(adj , child, 0, visited, n, ans);
        return ans;
    }
    
};