// The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

// For example, for arr = [2,3,4], the median is 3.
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
// Implement the MedianFinder class:

// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

// Example 1:

// Input
// ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
// [[], [1], [2], [], [3], []]
// Output
// [null, null, null, 1.5, null, 2.0]

#include<bits/stdc++.h>
using namespace std;
class MedianFinder {
public:
    priority_queue<int> q1;
    priority_queue<int,vector<int>,greater<int>> q2;
    
    void balance()
    {
        while(q1.size()<q2.size())
        {
            q1.push(q2.top());
            q2.pop();
        }
        
        if(q1.size()-q2.size()>1)
        {
            q2.push(q1.top());
            q1.pop();
        }
    }
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(q1.empty() || num<q1.top())
            q1.push(num);
        else
            q2.push(num);
        
        balance();
    }
    
    double findMedian() {
        if(q1.size()>q2.size())
            return q1.top();
        else
            return ((float)q1.top()+q2.top())/2;
    }
};
