// Alex is very fond of traveling. There are n cities, labeled from 1 to n.  You are also given flights, a list of travel flights as directed weighted edges flights[i] = (ui,vi,wi) where ui is the source node, vi is the target node, and wi is the price it takes for a person to travel from source to target.
// Currently, Alex is in k'th city and wants to visit one city of his choice. Return the minimum money Alex should have so that he can visit any city of his choice from k'th city. If there is a city that has no path from k'th city, which means Alex can't visit that city, return -1. 
// Alex always takes the optimal path. He can any city via another city by taking multiple flights.
 

// Example 1:

// Input:
// n: 4
// k: 2
// flights size: 3
// flights: [[2,1,1],[2,3,1],[3,4,1]]
// Output:
// 2
// Explanation:
// to visit 1 from 2 takes cost 1
// to visit 2 from 2 takes cost 0
// to visit 3 from 2 takes cost 1
// to visit 4 from 2 takes cost 2,
// 2->3->4
// So if Alex wants to visit city 4
// from 2, he needs 2 units of money

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        vector<vector<vector<int>>> graph(n+1);
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            graph[u].push_back({v,w});
        }
        vector<int> dist(n+1,-1);
        queue<vector<int>> q;
        dist[k]=0;
        q.push({k, dist[k]});
        int ans=INT_MIN;
        while(!q.empty()){
            vector<int> front=q.front();
            q.pop();
            int node=front[0];
            int cost=front[1];
            for(auto it: graph[node]){
                int node_x=it[0];
                int cost_x=it[1];
                if(dist[node_x]==-1){
                    dist[node_x]=cost+cost_x;
                    q.push({node_x, dist[node_x]});
                }
                else if(dist[node_x]>cost+cost_x){
                    dist[node_x]=cost+cost_x;
                    q.push({node_x, dist[node_x]});
                }
                
            }
        }
        for(int i=1;i<dist.size();i++){
            if(dist[i]!=-1){
                ans=max(ans, dist[i]);
            }
            else 
                return -1;
        }
        return ans;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}