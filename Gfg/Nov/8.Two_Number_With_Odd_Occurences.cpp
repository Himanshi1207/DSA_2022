// Given an unsorted array, Arr[] of size N and that contains even number of occurrences for all numbers except two numbers. Find the two numbers in decreasing order which has odd occurrences.

// Example 1:

// Input:
// N = 8
// Arr = {4, 2, 4, 5, 2, 3, 3, 1}
// Output: {5, 1} 
// Explaination: 5 and 1 have odd occurrences.

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        vector<long long>ans;
        long long as=0;
        
        for(ll i=0;i<N;i++)
        {
            as=as^Arr[i];
        }
        
        ll last_bit=(as)&(~as+1);
        ll f_ans=0,s_ans=0;
        for(ll i=0;i<N;i++)
        {
            if((last_bit&Arr[i])!=0)
            {
                f_ans^=Arr[i];
            }
            else
            {
                s_ans^=Arr[i];
            }
        }
        ans.push_back(f_ans);
        ans.push_back(s_ans);
        sort(ans.begin(),ans.end(),greater<int>());
        
        return ans;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}