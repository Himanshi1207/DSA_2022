// Given an infinite supply of each denomination of Indian currency { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 } and a target value N.
// Find the minimum number of coins and/or notes needed to make the change for Rs N. You must return the list containing the value of coins required. 


// Example 1:

// Input: N = 43
// Output: 20 20 2 1
// Explaination: 
// Minimum number of coins and notes needed 
// to make 43. 


#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> minPartition(int target)
    {
        // code here
        vector<int> coins={1,2,5,10,20,50,100,200,500,2000};
        vector<int> ans;
        int idx=9;
        while(target>0){
            if(coins[idx]<=target){
                ans.push_back(coins[idx]);
                target=target-coins[idx];
            }
            else {
                idx--;
            }
        }
        return ans;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}