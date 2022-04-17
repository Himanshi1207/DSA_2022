#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int> s;
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
    s.erase(3);
    for(auto i:s){
        cout<<i<<" ";
    }
    return 0;
}