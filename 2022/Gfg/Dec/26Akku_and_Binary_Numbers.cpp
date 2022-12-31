// Akku likes binary numbers and she likes playing with these numbers. Her teacher once gave her a question.For given value of  L and R, Akku have to find the count of number X, which have only three-set bits in it's binary representation such that "L ≤ X ≤ R".Akku is genius, she solved the problem easily. Can you do it ??

// Example 1:

// Input:
// L = 11 and R = 19 
// Output: 4
// Explanation:
// There are 4 such numbers with 3 set bits in 
// range 11 to 19.
// 11 -> 1011
// 13 -> 1101
// 14 -> 1110
// 19 -> 10011

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
vector<long long>pre;
    void precompute()
    {
       for(int i=0;i<63;i++){
           for(int j=i+1;j<63;j++){
               for(int k=j+1;k<63;k++){
                   long long tmp=(1ll<<i)+(1ll<<j)+(1ll<<k);
                   pre.push_back(tmp);
               }
           }
       }
       sort(pre.begin(),pre.end());
    }
    
    long long solve(long long l, long long r){
    int hi=upper_bound(pre.begin(),pre.end(),r)-pre.begin();
    int lo=lower_bound(pre.begin(),pre.end(),l)-pre.begin();
    return hi-lo;
    }
    
};
int main()
{
    int t;
    Solution ob;
    ob.precompute();
    cin>>t;
    while(t--)
    {
        long long l,r;
        cin>>l>>r;
        cout << ob.solve(l, r) << endl; 
    }
    return 0;
}