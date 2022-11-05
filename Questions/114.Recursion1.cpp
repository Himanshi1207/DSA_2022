#include<bits/stdc++.h>
using namespace std;
void removeX(char ch[]){
    if(ch[0]=='\0')
    return;
    if(ch[0]!='x'){
        removeX(ch+1);
    }
    else{
        int i=1;
    for(;ch[i]!='\0';i++){
        ch[i-1]=ch[i];
    }
    ch[i-1]=ch[i];
    removeX(ch);
    }
}
int length(char ch[]){
    if(ch[0]=='\0')
    return 0;
    return length(ch+1)+1;
}
int main(){
    char ch[100];
    cin>>ch;
    cout<<length(ch)<<endl;
    removeX(ch);
    cout<<ch;
    return 0;
}