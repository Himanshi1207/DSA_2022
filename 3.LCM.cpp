#include<iostream>
using namespace std;
// since a*b = gcd(a,b)*lcm(a,b)
// therefore lcm(a,b)=a*b/gcd(a,b)
int gcd(int a, int b){
    //usign euclid's algorithm
    if(b==0)
    return a;
    return gcd(b,a%b);
}
int main(){

    int a,b;
    cout<<"enter two numbers"<<endl;
    cin>>a>>b;
    cout<<"the lcm of two numbers "<<a<<" and "<<b<<" is "<<(a*b)/gcd(a,b);

    return 0;
}