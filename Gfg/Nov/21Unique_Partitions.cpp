// Given a positive integer n, generate all possible unique ways to represent n as sum of positive integers.

// Note: The generated output is printed without partitions. Each partition must be in decreasing order. Printing of all the partitions is done in reverse sorted order. 

// Example 1:

// Input: n = 3
// Output: 3 2 1 1 1 1
// Explanation: For n = 3, 
// {3}, {2, 1} and {1, 1, 1}.


#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	set<vector<int>> s;
	vector<int> ss;
	
	void dfs(vector<int> ans, int n, int i)
	{
	    if(n == 0)
	    {
	        sort(ans.begin(), ans.end(), greater<int>());
	        s.insert(ans);
	        return;
	    }
	    
	    if(n < 0 || i == ss.size())
	    {
	        return;
	    }
	    
	    dfs(ans, n, i+1);
	    ans.push_back(ss[i]);
	    dfs(ans, n-ss[i], i);
	}
	
    vector<vector<int>> UniquePartitions(int n) {
        // Code here
        
        for(int i = 1; i <= n; i++)
        {
            ss.push_back(i);
        }
        
        vector<int> ans;
        dfs(ans, n, 0);
        
        vector<vector<int>> sol(s.begin(), s.end());
        sort(sol.begin(), sol.end(), greater<vector<int>>());
        
        return sol;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}