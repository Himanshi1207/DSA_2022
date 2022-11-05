// SOLUTION OF SCALER CODEX 2.0 
// you are given a big number in form of a string A of characters from 0 to 9, return 1 if it is divisible by 30 and 0 otherwise.
// Constraints
// 1<=length of A<=10^5
// for example, A="3030300" then it is divisible by 30,
// for example, A="2311" then it is not divisible by 30
#include<iostream>
using namespace std;
bool checkDivisibilityByThirty(string s){
    int n=s.size();
    if(s[n-1]!='0')
    return 0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=s[i];
    }
    if(sum%3==0)
    return 1;

    return 0;
}
int main(){
    string s;
    cout<<"enter any string : ";
    cin>>s;
    cout<<checkDivisibilityByThirty(s);
    return 0;
}