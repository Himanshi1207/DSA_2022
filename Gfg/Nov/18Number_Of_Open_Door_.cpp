// Consider a long alley with a N number of doors on one side. All the doors are closed initially. You move to and fro in the alley changing the states of the doors as follows: you open a door that is already closed and you close a door that is already opened. You start at one end go on altering the state of the doors till you reach the other end and then you come back and start altering the states of the doors again.
// In the first go, you alter the states of doors numbered 1, 2, 3, , n.
// In the second go, you alter the states of doors numbered 2, 4, 6
// In the third go, you alter the states of doors numbered 3, 6, 9
// You continue this till the Nth go in which you alter the state of the door numbered N.
// You have to find the number of open doors at the end of the procedure.

 

// Example 1:

// Input:
// N = 2
// Output:
// 1
// Explanation:
// Initially all doors are closed.
// After 1st go, all doors will be opened.
// After 2nd go second door will be closed.
// So, Only 1st door will remain Open.
// Approach : The problems boils down to counting the numbers from 1 to N which have odd number of divisors/factors.

// The only numbers which have odd number of factors are perfect squares.

// Ex: 4 is a perfect square and its factors are 1,2 and 4. So 4 has 3 factors

// Similarly 9 is a perfect square and its factors are 1,3 and 9. So 9 has 3 factors.

// When you compute square root of a number N then you get the count/number of perfect squares from 1 to N.

// Ex: sqrt(4) = 2 which means that there are 2 perfect squares between 1 and 4 which are 1 and 4.

// sqrt(9) = 3 which means that there are 3 perfect squares between 1 and 4 which are 1,4 and 9.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int noOfOpenDoors(long long N) {
        // code here
        return (int)sqrt(N);
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.noOfOpenDoors(N) << endl;
    }
    return 0;
}