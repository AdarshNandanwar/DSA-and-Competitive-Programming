// https://leetcode.com/problems/image-overlap/

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size(), res = 0;
        for(int x = -n+1; x<n; x++){
            for(int y = -n+1; y<n; y++){
                int count = 0;
                // ni, mi : intersection dimentions
                int ni = min(n-1, n-1+y)-max(0, y)+1;
                int mi = min(n-1, n-1+x)-max(0, x)+1;
                int ya = 0,xa = 0, yb = 0, xb = 0;
                if(x<0){
                    if(y<0){
                        yb = -y;
                        xb = -x;
                    } else {
                        ya = y;
                        xb = -x;
                    }
                } else {
                    if(y<0){
                        xa = x;
                        yb = -y;
                    } else {
                        ya = y;
                        xa = x;
                    }
                }
                for(int i = 0; i<ni; i++){
                    for(int j = 0; j<mi; j++){
                        count += (A[ya+i][xa+j] == 1 and B[yb+i][xb+j] == 1);
                    }
                }
                res = max(res, count);
            }
        }
        return res;
    }
};