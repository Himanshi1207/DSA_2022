// You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.

// Return a list answer of size 2 where:

// answer[0] is a list of all players that have not lost any matches.
// answer[1] is a list of all players that have lost exactly one match.
// The values in the two lists should be returned in increasing order.

// Note:

// You should only consider the players that have played at least one match.
// The testcases will be generated such that no two matches will have the same outcome.
 

// Example 1:

// Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
// Output: [[1,2,10],[4,5,7,8]]
// Explanation:
// Players 1, 2, and 10 have not lost any matches.
// Players 4, 5, 7, and 8 each have lost one match.
// Players 3, 6, and 9 each have lost two matches.
// Thus, answer[0] = [1,2,10] and answer[1] = [4,5,7,8].

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2, vector<int>());
        map<int, int> win, lose; //created map as we have to return ans in increasing order so map will help in two ways that is it stores {key, value} pairs in increasing order also it will store the frequency of wins and lose.
        for(int i=0;i<matches.size();i++){
            int w=matches[i][0];
            int l=matches[i][1];
            win[w]++;  // adding the winners to the map
            lose[l]++;  // adding losers to the map
        }
		// iterating over the winners and if there is any winner who is also a loser then we don't add it in the winners list as winner is the one who never lost
        for(auto it: win){
            if((it.second)>0 and lose.find(it.first)==lose.end()){  //checking if the winner is also a loser then it will be present in the loser map
                ans[0].push_back(it.first);
            }
        }
		// iterating over the losers and if the loser has lost only one match then only adding it into the losers list...
        for(auto it: lose){
            if(it.second==1){
                ans[1].push_back(it.first);
            }
        }
        return ans;
    }
};