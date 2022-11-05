#include<bits/stdc++.h>
using namespace std;
const int N=102, mod=1e9+7;
int a[N];
int dp[N][N];
int mcm(int i, int j){
    if(i==j)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    dp[i][j]=mod;
    for(int k=i;k<j;k++){
        dp[i][j]=min(dp[i][j],mcm(i,k)+mcm(k+1,j)+a[i-1]*a[k]*a[j]);
    }
    return dp[i][j];
}
int main()
{
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dp[i][j]=-1;
        }
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<mcm(1,n-1)<<endl;
    return 0;
}