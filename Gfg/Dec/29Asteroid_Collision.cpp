// We are given an integer array asteroids of size N representing asteroids in a row. For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are of same size, both will explode. Two asteroids moving in the same direction will never meet.
 

// Example 1:

// Input:
// N = 3
// asteroids[ ] = {3, 5, -3}
// Output: {3, 5}
// Explanation: The asteroid 5 and -3 collide resulting in 5. The 5 and 3 never collide.
// Example 2:

// Input:
// N = 2
// asteroids[ ] = {10, -10}
// Output: { }
// Explanation: The asteroid -10 and 10 collide exploding each other.
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
    stack <int> st;
    for(int i=0;i<asteroids.size();i++){
        if(asteroids[i] > 0)
            st.push(asteroids[i]);
        else{
            bool flag = false;
            while(!st.empty()){
                if(st.top() < 0){
                    st.push(asteroids[i]);
                    break;
                }
                else if (st.top() < -1 * asteroids[i])
                    st.pop();
                else
                    break;
            }
            if(!st.empty() && st.top() == -1 * asteroids[i])
                st.pop();

            if(st.empty())
                st.push(asteroids[i]);
        }
    }
    vector <int> res;
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends