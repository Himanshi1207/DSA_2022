#include <bits/stdc++.h>
using namespace std;
// Tree Bias question using BFS

// Ram was learning the tree data structure when John saw him. Seeing Ram John challenged him to calculate the bias of the tree.

// The bias was defined as the sum of the depths of all tree nodes.

// Given a tree help Ram in finding the bias of the tree. Consider node with value 1 as the root of the tree

// And consider the depth of the root node as 0.
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin>>n;
     vector<int> adj[n+1];
     for(int i=0;i<n-1;i++){
         int x,y;
         cin>>x>>y;
         adj[x].push_back(y);
         adj[y].push_back(x);
     }

    vector<int> visited(n+1,0);
     queue<int> q;
     int root=0;
     q.push(1);
     visited[1]=1;
     int ans=0;
     while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
         int top=q.front();
         q.pop();
         ans+=root;
         for(auto it: adj[top]){
             if(visited[it]==1)
                continue;
             q.push(it);
             visited[it]=1;
         }
        }
         root++;

     }
     cout<<ans<<endl;
    return 0;
}