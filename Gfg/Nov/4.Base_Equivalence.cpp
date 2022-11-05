// Given a number (n) and no. of digits (m) to represent the number, we have to check if we can represent n using exactly m digits in any base from 2 to 32.

// Example 1:

// Input: n = 8, m = 2
// Output: Yes 
// Explanation: Possible in base 3 as 8 in base 3 is 22.  

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string baseEquiv(int n, int m){
        // code here
        int i=2;
        while(i<33){
            if(int(log(n)/log(i))+1==m){
                return "Yes";
            }
            i++;
        }
        return "No";
    }
};