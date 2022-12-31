// We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

// Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

 

// Example 1:

// Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
// Output: true
// Explanation: group1 [1,4] and group2 [2,3].

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        int i, j, k, u, v, s;
        vector<vector<int>> graph(N, vector<int>());
        queue<int> q;
        vector<int> visited(N, 0);
        for(i = 0; i < dislikes.size(); i++){
            u = dislikes[i][0] - 1;
            v = dislikes[i][1] - 1;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        for(i = 0; i < N; i++){
            if(visited[i] != 0){
                continue;
            }
            q.push(i);
            visited[i] = 1;
            while(!q.empty()){
                s = q.size();
                for(j = 0; j < s; j++){
                    u = q.front();
                    q.pop();
                    for(k = 0; k < graph[u].size(); k++){
                        v = graph[u][k];
                        if(visited[v] == 0){
                            q.push(v);
                            visited[v] = visited[u] == 1 ? 2 : 1;
                        }
                        
                        if(visited[v] == visited[u]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
        
    }
};