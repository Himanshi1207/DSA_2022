// On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

// A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

// Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

 

// Example 1:

// Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
// Output: 5
// Explanation: One way to remove 5 stones is as follows:
// 1. Remove stone [2,2] because it shares the same row as [2,1].
// 2. Remove stone [2,1] because it shares the same column as [0,1].
// 3. Remove stone [1,2] because it shares the same row as [1,0].
// 4. Remove stone [1,0] because it shares the same column as [0,0].
// 5. Remove stone [0,1] because it shares the same row as [0,0].
// Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.

#include<bits/stdc++.h>
using namespace std;
vector<int> parent;

int removeStones(vector<vector<int>>& stones) {
	unordered_map<int, vector<int>> rowmap, colmap;
	for(int i = 0; i < stones.size(); i++) {
		rowmap[stones[i][0]].push_back(i);
		colmap[stones[i][1]].push_back(i);
	}

	for(int i = 0; i < stones.size(); i++) parent.push_back(i);
	for(int i = 0; i < stones.size(); i++) {
		for(int j : rowmap[stones[i][0]]) unite(i, j);
		for(int j : colmap[stones[i][1]]) unite(i, j);
	}

	unordered_set<int> unique;
	for(int n : parent) unique.insert(find(n));
	return stones.size() - unique.size();
}

int find(int n) { return parent[n] == n ? n : parent[n] = find(parent[n]); }

void unite(int a, int b) { parent[find(a)] = find(b); }