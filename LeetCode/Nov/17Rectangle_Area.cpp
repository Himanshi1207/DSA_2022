// Given the coordinates of two rectilinear rectangles in a 2D plane, return the total area covered by the two rectangles.

// The first rectangle is defined by its bottom-left corner (ax1, ay1) and its top-right corner (ax2, ay2).

// The second rectangle is defined by its bottom-left corner (bx1, by1) and its top-right corner (bx2, by2).

 

// Example 1:

// Rectangle Area
// Input: ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
// Output: 45

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        int left_boundary = max(ax1, bx1);
        int right_boundary = min(ax2, bx2);
        
        int top_boundary = min(ay2, by2);
        int bottom_bondary = max(ay1, by1);
        
        
        int area_1 = (ax2 - ax1)*(ay2 - ay1);
        int area_2 = (bx2 - bx1)*(by2 - by1);
        int intersection = 0;
        
        if( (left_boundary < right_boundary) && (bottom_bondary < top_boundary) ){
            // area_1 and area_2 has overlapped area
            intersection = ( right_boundary - left_boundary ) * ( top_boundary - bottom_bondary );
        }

        
        return area_1 + area_2 - intersection;
    }
};