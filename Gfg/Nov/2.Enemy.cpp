// You live in Geek land. Geek land can be seen as a grid of shape N x M.There are K enemy at K positions. Each enemy blocks the row and column to which it belongs. You have to find the largest continuous area that is not blocked.No two enemies share the same row or the same column.

// Example 1:

// Input:
// N = 2
// M = 2
// K = 1
// enemy[]={{2,2}}
// Output:
// 1
// Explanation:
// Since only (1,1) cell is free from the enemy hence answer is 1.
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            //  code here
            if(k==0)
                return n*m;
            vector<int> row, col;
            for(int i=0;i<enemy.size();i++){
                row.push_back(enemy[i][0]);
                col.push_back(enemy[i][1]);
            }
            sort(row.begin(), row.end());
            sort(col.begin(), col.end());
            int rowDiff=max(row[0]-1, n-row[k-1]);
            int colDiff=max(col[0]-1, n-col[k-1]);
            for(int i=1;i<k;i++){
                rowDiff=max(rowDiff, row[i]-row[i-1]-1);
                colDiff=max(colDiff, col[i]-col[i-1]-1);
            }
            for(int i=1;i<k;i++){
                rowDiff=max(rowDiff,row[i]-row[i-1]-1);
            }
            for(int i=1;i<k;i++){
                colDiff=max(colDiff,col[i]-col[i-1]-1);
            }
            for(int i=1;i<k;i++){
            }
            return rowDiff*colDiff;
        }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}