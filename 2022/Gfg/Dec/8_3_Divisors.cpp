// You are given a list of q queries and for every query, you are given an integer N.  The task is to find how many numbers(less than or equal to N) have number of divisors exactly equal to 3.

// Example 1:

// Input:
// q = 1
// query[0] = 6
// Output:
// 1
// Explanation:
// There is only one number 4 which has
// exactly three divisors 1, 2 and 4 and
// less than equal to 6.

#include<bits/stdc++.h> 
using namespace std; 
class Solution
{
public:
    bool chkdivi(int n){
        if(n==1 || n==2) return false;
        if(floor(sqrt(n))!=ceil(sqrt(n))) return false;
        for(int i=2;i*i<n;i++){
            if(n%i==0) return false;
        }
        return true;
    }

    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // Write your code here
        vector<int> ans;
        int num;
        
        for(int i=0;i<q;i++){
            num = query[i];
            int cnt=0;
            for(int j=1;j<=num;j++){
                 
                if(chkdivi(j)){
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}