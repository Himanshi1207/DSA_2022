// Given a sorted array of positive integers. Your task is to rearrange the array elements alternatively i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on.
// Note: Modify the original array itself. Do it without using any extra space. You do not have to return anything.

// Example 1:

// Input:
// n = 6
// arr[] = {1,2,3,4,5,6}
// Output: 6 1 5 2 4 3
// Explanation: Max element = 6, min = 1, 
// second max = 5, second min = 2, and 
// so on... Modified array is : 6 1 5 2 4 3.

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    { 
    	
    	// Your code here
    	long long maxi=arr[n-1]+1, start=0, end=n-1;
    	for(long long i=0;i<n;i++){
    	    if(!(i%2)){
    	        arr[i]+=(arr[end--]%maxi)*maxi;
    	    }
    	    else{
    	        arr[i]+=(arr[start++]%maxi)*maxi;
    	    }
    	}
    	for(long long i=0;i<n;i++){
    	    arr[i]/=maxi;
    	}
    }
};

int main() 
{
    int t;
    
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;      
        long long arr[n];
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 
