// There is a carpet of a size a*b [length * breadth]. You are given a box of size c*d. The task is, one has to fit the carpet in the box in a minimum number of moves. 

// In one move, you can either decrease the length or the breadth of the carpet by half (floor value of its half).

// Note: One can even turn the carpet by 90 degrees any number of times, wont be counted as a move.

 

// Example 1:

// Input:
// A = 8, B = 13
// C = 6, D = 10
// Output:
// Minimum number of moves: 1
// Explanation:
// Fold the carpet by breadth, 13/2 i.e. 6, 
// so now carpet is 6*8 and can fit fine.
 

// Example 2:

// Input:
// A = 4, B = 8
// C = 3, D = 10
// Output:
// Minimum number of moves: 1
// Explanation: Fold the carpet by length , 4/2 i.e. 2,
// so now carpet is 2*8 and can fit fine.
 

// Your Task:
// You don't need to read input or print anything. You only need to complete the function carpetBox() that takes an integer A, B, C and D as input and returns an integer denoting the minimum numbers of moves required to fit the carpet into the box.

 

// Expected Time Complexity: O( max( log(a), log(b) ) ) .
// Expected Auxiliary Space: O(1) .

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
        //code here
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends