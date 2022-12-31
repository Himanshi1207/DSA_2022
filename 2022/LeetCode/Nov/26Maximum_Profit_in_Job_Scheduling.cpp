// We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

// You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

// If you choose a job that ends at time X you will be able to start another job that starts at time X.

 

// Example 1:



// Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
// Output: 120
// Explanation: The subset chosen is the first and fourth job. 
// Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
// Example 2:



// Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
// Output: 150
// Explanation: The subset chosen is the first, fourth and fifth job. 
// Profit obtained 150 = 20 + 70 + 60.


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>> jobs(n, vector<int> (3));
        for(int i=0;i<n;i++){
            jobs[i]={endTime[i], startTime[i], profit[i]};
        }
//         using end time
        sort(jobs.begin(), jobs.end());
        vector<int> dp(n);
        int ans=0;
        for(int i=0;i<n;i++){
            dp[i]=jobs[i][2];
            if(i==0){
                ans=max(ans, dp[i]);
                    continue;
            }
            dp[i]=max(dp[i],dp[i-1]);
            int curr=jobs[i][1];
            for(int j=i-1;j>=0;j--){
                if(jobs[j][0]<=curr){
                    dp[i]=max(dp[i],dp[j]+jobs[i][2]);
                    break;
                }
            }
            ans=max(ans, dp[i]);
        }
        return ans;
    }
};