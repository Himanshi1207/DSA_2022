#include<iostream>
using namespace std;
// euclid's algorithm
// time complexity - O(log(min(a, b))
// space complexity - O(1)
int eugcd(int a,int b){
    // using repetive subtraction
    while (a!=b)
    {
        if(a>b)
        a=a-b;
        else
        b=b-a;
    }
    return a;
}
int optimisedgcd(int a,int b){
    // more optimised as we use remainder in every call
    if(b==0)
    return a;
    return(optimisedgcd(b,a%b));
}
int main(){
    int a,b;
    cout<<"enter two numbers"<<endl;
    cin>>a>>b;
    cout<<"the gcd of the two numbers is "<<optimisedgcd(a,b);
    return 0;
}