// https://www.interviewbit.com/problems/distinct-numbers-in-window/

vector<int> Solution::dNums(vector<int> &A, int B) {
    int n = A.size();
    vector<int> res;
    if(n<B) return res;
    unordered_map<int, int> freq;
    int distinct = 0;
    for(int i = 0; i<B; i++){
        if(freq[A[i]] == 0) distinct++;
        freq[A[i]]++;
    }
    res.push_back(distinct);
    for(int i = B; i<n; i++){
        if(freq[A[i]] == 0) distinct++;
        freq[A[i]]++;
        freq[A[i-B]]--;
        if(freq[A[i-B]] == 0) distinct--;
        res.push_back(distinct);
    }
    return res;
}
