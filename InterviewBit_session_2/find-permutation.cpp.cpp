// https://www.interviewbit.com/problems/find-permutation/

// Method 1:

vector<int> Solution::findPerm(const string A, int B) {
    if(B == 0) return {};
    int hi = B, lo = 1;
    vector<int> res;
    for(int i = 0; i<A.length(); i++){
        if(A[i] == 'I'){
            res.push_back(lo++);
        } else {
            res.push_back(hi--);
        }
    }
    res.push_back(lo);
    return res;
}
