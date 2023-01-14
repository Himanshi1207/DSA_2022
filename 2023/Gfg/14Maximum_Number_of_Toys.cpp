// You are given N toys in a shop .
// The cost of each toy is represented by an array A[]. You are given Q queries, For ith query, You have a C amount of money which you can use to purchase the toys. Also there are K broken toys and you won't purchase them. The task is to calculate the maximum number of toys you can purchase using the C amount of money.

// Note: 1 based indexing is used. Each query is treated independently. 
// Query definition: The first element represents an integer C where C=Queries[i][0].
// The second element represents an integer K, where K = Queries[i][1].
// The next K integers represent the indices of broken toys which are Queries[i][j] ,j>1

// Example 1:

// Input:
// N = 5
// A[] = {8, 6, 9, 2, 5}
// Q = 2
// Query[][] = {{12,2,3,4},{30,0}}
// Output:
// 2 5
// Explanation:
// Query 1: C = 12, K = 2 , 
// Indices of Broken toys is {3,4}
// Indices of Available toys are {1,2,5}
// If we purchase the toys 2 and 5 , 
// then cost = A[2]+A[5]= 6+5 = 11,
// Therefore,We purchase the 2 toys 
// using 11 amount of money.
// Query 2: C = 30, K = 0
// There is no broken toy. 
// We can purchase all toys,
// cost = A[1]+A[2]+A[3]+A[4]+A[5]= 30
// Therefore,We purchase the 5 toys
// using 30 amount of money.
// Example 2:

// Input:
// N = 2
// A[] = {3,3}
// Q = 1
// Query[][] = {{1,0}}
// Output:
// 0
// Explanation:
// Query 1: C = 1, K = 0 , 
// There is no broken toy. 
// We have not enough amount to purchase 
// any toy.
// Your Task: 
// You don't need to read input or print anything. Your task is to complete the function maximumToys() which takes the integer N and array A[ ],  integer Q and 2D array Queries[][] as input parameters and returns the array of answers of each query.

// Expected Time Complexity: O(NLogMx + Q*K*LogMx + Q*(LogMx)2)
// Expected Auxiliary Space: O(Mx)
// Where Mx is the maximum element present in the array A[i].

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ A[i] ≤ 106
// 1 ≤ Q ≤ 104
// 1 ≤ C ≤ 109
// 0 ≤ K ≤ 10
// 1 ≤ Queries[i][j] ≤ N, j>1


//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

//User function Template for C++
//User function Template for C++
//Back-end complete function Template for C++

const int N=1e6+5;
int fr[N];
class tree{
public:

  vector<long long> bit;
  
  
  tree(){
    bit=vector<long long>(N);
  }
  
  
  void add(int node,int v)
  {
     for(;node<N;node+=(node&(-node)))
      bit[node]+=v;
  }
  
  
  long long get(int node)
  {
    long long x=0;
    for(;node>0;node-=(node&(-node)))
      x+=bit[node];
    return x;
  }
  
};
tree obj1,obj2;


class Solution{
public:
  vector<int> maximumToys(int N,vector<int> A,int Q,vector<vector<int>> Queries){
    vector<int> res;

    for(auto i:A){
      fr[i]++;
    }

    for(int i=0;i<A.size();i++){
      obj1.add(A[i],A[i]);
      obj2.add(A[i],1);
    }
    for(auto i:Queries){
      long long C=i[0];
      for(int j=2;j<i.size();j++){
        obj1.add(A[i[j]-1],-A[i[j]-1]);
        obj2.add(A[i[j]-1],-1);
      }
      long long lw=1,hg=1e6;
      long long pos=1e6;
      while(lw<=hg){
        int mid=(lw+hg)/2;
        if(obj1.get(mid)>=C){
          pos=mid;
          hg=mid-1;
        }
        else{
          lw=mid+1;
        }
      }

      long long ans=obj2.get(pos-1);
      long long mx=min((C-obj1.get(pos-1))/pos,(long long)fr[pos]);
      ans+=mx;
      res.push_back(ans);
      for(int j=2;j<i.size();j++){
        obj1.add(A[i[j]-1],A[i[j]-1]);
        obj2.add(A[i[j]-1],1);
      }
    }
    for(int i=0;i<A.size();i++){
      obj1.add(A[i],-A[i]);
      obj2.add(A[i],-1);
      fr[A[i]]--;
    }
    return res;
  }
};

//{ Driver Code Starts.
int main() {
 int t=1;
 cin>>t;
 for(int i=1;i<=t;i++){
    int N;
    cin>>N;
    vector<int>A(N);
    for(auto &i:A){
      cin>>i;
    }
    int Q;
    cin>>Q;
    vector<vector<int>> Queries(Q);
    for(int i=0;i<Q;i++){
      int x,y;
      cin>>x>>y;
      Queries[i].push_back(x);
      Queries[i].push_back(y);
      for(int j=0;j<Queries[i][1];j++){
        cin>>x;
        Queries[i].push_back(x);
      }
    }
    Solution obj;
    auto ans =obj.maximumToys(N,A,Q,Queries);
    for(auto i:ans)
      cout<<i<<" ";
    cout<<endl;
 }
}
// } Driver Code Ends