// https://leetcode.com/problems/rectangle-area/

class Solution {
public:
    int area(int A, int B, int C, int D){
        return abs(A-C)*abs(B-D);
    }
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int a1 = area(A, B, C, D), a2 = area(E, F, G, H);
        if(C<=E or D<=F or G<=A or H<=B){
            // no overlap
            return a1+a2;
        } else {
            // overlap
            int x1 = max(A, E), y1 = max(B, F), x2 = min(C, G), y2 = min(D, H);
            return a1-area(x1, y1, x2, y2)+a2;
        }
    }
};