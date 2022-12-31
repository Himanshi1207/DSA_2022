// Given a positive number X. Find the largest Jumping Number which is smaller than or equal to X. 
// Jumping Number: A number is called Jumping Number if all adjacent digits in it differ by only 1. All single-digit numbers are considered as Jumping Numbers. For example 7, 8987 and 4343456 are Jumping numbers but 796, 677 and 89098 are not.

 

// Example 1:

// Input:
// X = 10
// Output:
// 10
// Explanation:
// 10 is the largest Jumping Number
// possible for X = 10.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  void bfs(long long x, long long num, long long &ans){
      queue<long long > q;
      q.push(num);
      while(!q.empty()){
          num=q.front();
          q.pop();
          if(num<=x){
              ans=max(ans, num);
              int last=num%10;
              if(last!=9)
                  q.push((num*10)+(last+1));
              if(last != 0)
                  q.push((num*10)+(last-1));
          }
      }
  }
    long long jumpingNums(long long X) {
        // code here
        long long ans=0;
        for(long long i=1;i<=9 and i<=X;i++)
            bfs(X,i,ans);
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}