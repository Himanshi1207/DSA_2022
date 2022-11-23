// Given a positive number n. You need to write a program to find the maximum sum of distinct numbers such that the LCM of all these numbers is equal to n.

// Example 1:

// Input: n = 2
// Output: 3 
// Explanation: The distinct numbers you can have are 
// just 1 and 2 and their sum is equal to 3.
// Example 2:

// Input: n = 5
// Output: 6
// Explanation: The distinct numbers you can have 
// are just 1 and 5 and their sum is equal to 6.

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    long long int maxSumLCM(int n) 
    {
        long long int ans = 0;
        
        for(int i=1; i*i<=n; i++)
		if(n%i == 0)
		{
			if(n/i == i)
				ans += i;
			else
				ans += i + (n/i);
		}
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n;
        cin >> n ;
        Solution ob;
        cout<<ob.maxSumLCM(n)<<endl;
    }
    return 0;
}
