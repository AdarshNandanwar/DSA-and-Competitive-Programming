class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int p1 = 0, p2 = 0, max_len = 1, next, n = A.size();
        
        while(p2<n){
            p2++;
            if(p2<n && p1 == p2-1){
                if(A[p1] < A[p2]){
                    next = 0;
                } else if(A[p1] > A[p2]){
                    next = 1;
                } else {
                    p1++;
                }
            } else {
                if(p2<n && next && A[p2]>A[p2-1]){
                    next = 0;
                } else if(p2<n && !next && A[p2-1]>A[p2]){
                    next = 1;
                } else {
                    max_len = max(max_len, p2-p1);
                    p1 = p2-1;
                    if(p2>=n) continue;
                    if(A[p1] < A[p2]){
                        next = 0;
                    } else if(A[p1] > A[p2]){
                        next = 1;
                    } else {
                        p1++;
                    }
                }
            }
        }
        max_len = max(max_len, p2-p1);
        return max_len;
    }
};