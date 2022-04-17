#include<iostream>
#include<set>
using namespace std;
int main(){
    multiset<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(7);
    s.insert(3);
    s.insert(4);
    s.insert(4);
    s.insert(4);
    s.insert(1);
    s.insert(5);
    for(auto i:s){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<s.size()<<endl;
    s.erase(s.find(4));
    for(auto i:s)
    cout<<i<<" ";
    s.erase(4);
    cout<<endl;
    for(auto i:s){
        cout<<i<<" ";
    }
    return 0;
}