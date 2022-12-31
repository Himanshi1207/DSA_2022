// Given N non-negative integers a1,a2,....an where each represents a point at coordinate (i, ai). N vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i,0). Find two lines, which together with x-axis forms a container, such that it contains the most water.

// Note : In Case of single verticle line it will not be able to hold water.

// Example 1:

// Input:
// N = 4
// a[] = {1,5,4,3}
// Output: 6
// Explanation: 5 and 3 are distance 2 apart.
// So the size of the base = 2. Height of
// container = min(5, 3) = 3. So total area
// = 3 * 2 = 6.

#include<bits/stdc++.h>
using namespace std;

long long maxArea(long long height[], int len)
{
    // Your code goes here
    int l=0, r=len-1;
        int max_area=0;
        while(l<r){
            int lh=height[l];
            int rh=height[r];
            max_area=max(max_area, (r-l)*min(lh,rh));
            if(lh<rh)
                ++l;
            else
                --r;
        }
        return max_area;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}