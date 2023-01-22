// Given two integers A and B, the task is to find an integer X such that (X XOR A) is minimum possible and the count of set bit in X is equal to the count of set bits in B.

// Example 1:

// Input: 
// A = 3, B = 5
// Output: 3
// Explanation:
// Binary(A) = Binary(3) = 011
// Binary(B) = Binary(5) = 101
// The XOR will be minimum when x = 3
// i.e. (3 XOR 3) = 0 and the number
// of set bits in 3 is equal
// to the number of set bits in 5.
// Example 2:

// Input: 
// A = 7, B = 12
// Output: 6
// Explanation:
// (7)2= 111
// (12)2= 1100
// The XOR will be minimum when x = 6 
// i.e. (6 XOR 7) = 1 and the number 
// of set bits in 6 is equal to the 
// number of set bits in 12.
// Your task :
// You don't need to read input or print anything. Your task is to complete the function minVal() that takes integer A and B as input and returns the value of X according to the question.
 
// Expected Time Complexity : O(log MAX(A,B))
// Expected Auxiliary Space : O(1)
 
// Constraints :
// 1 <= A, B <= 109

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int countbetsetinb ; 
        
        int B = b;
        while(B)
        {   
            countbetsetinb+=B%2; 
            B/=2;
        }
        
        int noofbitstosetinx = countbetsetinb;
        int ans = 0;
        for(int i=31;i>=0 && noofbitstosetinx;i--)
        {
            if(a&(1<<i)) 
            {                  
                ans|=(1<<i); 
                noofbitstosetinx--; 
            }
            
        }
       
        for(int i=0;i<=31 && noofbitstosetinx;i++)
        {
            if((ans&(1<<i))==0)
            {ans|=(1<<i); 
                noofbitstosetinx--; 
            }
        }
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends