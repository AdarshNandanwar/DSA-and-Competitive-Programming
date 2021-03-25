// https://www.interviewbit.com/problems/max-continuous-series-of-1s/

// Method 1 (2 Pointers, O(n)):

vector<int> Solution::maxone(vector<int> &A, int B) {
    int n = A.size(), p1 = 0, p2 = 0, zeros = 0, maxLen = 0, st = -1;
    // [p1, p2)
    while(p2<n){
        if(A[p2++] == 0) zeros++;
        while(zeros>B) if(A[p1++] == 0) zeros--;
        if(maxLen < p2-p1){
            maxLen = p2-p1;
            st = p1;
        }
    }
    vector<int> res;
    for(int i = st; i<st+maxLen; i++) res.push_back(i);
    return res;
}
