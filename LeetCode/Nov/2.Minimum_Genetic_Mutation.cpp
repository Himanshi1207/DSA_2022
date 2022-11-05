// A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

// Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.

// For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
// There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

// Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.

// Note that the starting point is assumed to be valid, so it might not be included in the bank.

 

// Example 1:

// Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
// Output: 1
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        q.push(start);
        unordered_set<string> visited;
        visited.insert(start);
        int count=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                string node=q.front();
                q.pop();
                if(node==end)
                    return count;
                for(char ch:"ACGT"){
                    for(int j=0;j<node.size();j++){
                        string adjNode=node;
                        adjNode[j]=ch;
                                               if(!visited.count(adjNode) &&                  find(bank.begin(),bank.end(),adjNode)!= bank.end())
{
                            q.push(adjNode);
                            visited.insert(adjNode);
                        }
                    }
                }
            }
            count++;
        }
        return -1;
    }
};
int main(){
    return 0;
}