// https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/

vector<int> Solution::lszero(vector<int> &A) {
    int n = A.size(), maxLen = 0, maxEnd = -1;
    if(n == 0) return {};
    unordered_map<int, int> ind;
    ind[0] = -1;
    vector<int> prefix(A.begin(), A.end());
    for(int i = 0; i<n; i++){
        if(i > 0) prefix[i] += prefix[i-1];
        if(ind.count(prefix[i])){
            if(i-ind[prefix[i]] > maxLen){
                maxLen = i-ind[prefix[i]];
                maxEnd = i;
            }
        } else {
            ind[prefix[i]] = i;
        }
    }
    if(maxLen == 0) return {};
    vector<int> res;
    for(int i = maxEnd-maxLen+1; i<=maxEnd; i++) res.push_back(A[i]);
    return res;
}
