// Given a number N. Find if it can be expressed as sum of two prime numbers.

// Example 1:

// Input: N = 34
// Output: "Yes" 
// Explanation: 34 can be expressed as 
// sum of two prime numbers.

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPrime(int n)

    {

        for(int i=2;i*i<=n;i++)

        {

            if(n%i==0)

            return false;

        }

        return true;

    }

    string isSumOfTwo(int n){

        

        for(int i=2;i<n;i++)

        {

            

            if(isPrime(i) && isPrime(n-i))

            return "Yes";

        }

        return "No";

        

    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}
