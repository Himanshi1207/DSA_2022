// You are given an array trees where trees[i] = [xi, yi] represents the location of a tree in the garden.

// You are asked to fence the entire garden using the minimum length of rope as it is expensive. The garden is well fenced only if all the trees are enclosed.

// Return the coordinates of trees that are exactly located on the fence perimeter.

 

// Example 1:


// Input: points = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
// Output: [[1,1],[2,0],[3,3],[2,4],[4,2]]


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getRotationAngle(vector<int> A, vector<int> B, vector<int> C){
        return ((B[0]-A[0])*(C[1]-A[1]))-((B[1]-A[1])*(C[0]-A[0]));
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        if(trees.size()<=3)
            return trees;
        sort(trees.begin(), trees.end());
        vector<vector<int>> ltrees,rtrees;
        ltrees.push_back(trees[0]);
        ltrees.push_back(trees[1]);
        for(int i=2;i<trees.size();i++){
            int ls=ltrees.size();
            while(ltrees.size()>=2 and getRotationAngle(ltrees[ls-2],ltrees[ls-1], trees[i])>0){
                ltrees.pop_back();
                ls--;
            }
            ltrees.push_back(trees[i]);
        }
        rtrees.push_back(trees[trees.size()-1]);
        rtrees.push_back(trees[trees.size()-2]);
        for(int i=trees.size()-3;i>=0;i--){
            int rs=rtrees.size();
            while(rtrees.size()>=2 and getRotationAngle(rtrees[rs-2],rtrees[rs-1], trees[i])>0){
                rtrees.pop_back();
                rs--;
            }
            rtrees.push_back(trees[i]);
        }
        rtrees.pop_back();
        ltrees.pop_back();
        for(int i=0;i<rtrees.size();i++)
            ltrees.push_back(rtrees[i]);
        sort(ltrees.begin(), ltrees.end());
        ltrees.erase(std::unique(ltrees.begin(), ltrees.end()), ltrees.end());
        return ltrees;
    }
};