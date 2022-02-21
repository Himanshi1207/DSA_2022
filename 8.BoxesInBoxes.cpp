// UBER Question
// Bob wants to prank Frank on his birthday. He wants to put boxes within each other so that it will take Frank a lot of time to open each box only to realize in the end that Bob never wrapped his present in these boxes.

// The shopkeeper has N boxes of different sizes. Your task is to help Bob decide the maximum number of boxes he can pick to put inside another.

// Assuming that the boxes are two-dimensional, one box can fit into another if the length and breadth of one box are smaller than the length and breadth of the second one.

// Each box is represented as an array [length, breadth].Example #1
//  Input: N=2, boxes = [[2,3],[4,5]]
//  Output: 2
//  Explanation: The first box can be placed inside the second box.

//  Example #2
//  Input: N=3, boxes = [[2,3],[2,4],[5,6]]
//  Output: 2
//  Explanation: Either the first or the second box can be placed inside the third box.
// Note: You cannot rotate a box.

//  1<=length,breadth<=10^6
//  1<=N<=10^4
// [execution time limit] 1 seconds (cpp)

// [input] array.array.integer boxes

// Boxes is an array of arrays. For example, if there are N boxes available, the input will be
// boxes = [[l1,b1],[l2,b2],....] (of size N)

// [output] integer

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> v;
    int n;
    cout << "enter number of elements: ";
    cin >> n;
    for (int j = 0; j < n; j++)
    {
        vector<int> vec;
        int a, b;
        cin >> a >> b;
        vec.push_back(a);
        vec.push_back(b);
        v.push_back(vec);
    }
    sort(v.begin(),v.end());
    int ans = 1;
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i][0] < v[i + 1][0] && v[i][1] < v[i + 1][1])
        {
            // cout<<"enters"<<endl;
            ans++;
        }
        else
        {
            v.erase(v.begin() + i+1);
            // cout<<"vector after erase"<<endl;
            // for (int i = 0; i < v.size(); i++)
            // {
            //     for (int j = 0; j < v[i].size(); j++)
            //     {
            //         cout << v[i][j] << " ";
            //     }
            //     cout << endl;
            // }ṇ
            i--;
        }
    }
    cout <<"ANSWER IS "<< ans;
    return 0;
}
