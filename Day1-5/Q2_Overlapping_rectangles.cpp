/*
Given two rectangles, find if the given two rectangles overlap or not. A rectangle is denoted by providing the x and y coordinates of two points: the left top corner and the right bottom corner of the rectangle. Two rectangles sharing a side are considered overlapping.
*/
class Solution {
  public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        int x1 = L1[0], y1 = L1[1], x2 = R1[0], y2 = R1[1];
        int xd1 = L2[0], yd1 = L2[1], xd2 = R2[0], yd2 = R2[1];
        
        int left = max(xd1, x1), right = min(x2, xd2), top = min(y1, yd1), bottom = max(y2, yd2);
        
        if(left <= right && top >= bottom)
            return true;
        return false;
    }
};
