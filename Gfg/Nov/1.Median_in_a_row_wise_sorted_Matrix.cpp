
// Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.

// Example 1:

// Input:
// R = 3, C = 3
// M = [[1, 3, 5], 
//      [2, 6, 9], 
//      [3, 6, 9]]
// Output: 5
// Explanation: Sorting matrix elements gives 
// us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 


#include <bits/stdc++.h>
using namespace std;



class Solution{   
public:
    int cntSmaller(vector<int> arr, int t){
        int low=0, high=arr.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]<=t)
                low=mid+1;
            else
                high=mid-1;
        }
        return low;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here    
        int start=0, end=2000;
        int size=R*C;
        while(start<=end){
            int ans=0;
            int mid=(start+end)/2;
            for(int i=0;i<R;i++){
                ans+=cntSmaller(matrix[i], mid);
            }
            if(ans<=(size)/2)
                start=mid+1;
            else
                end=mid-1;
        }
        return start;
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends