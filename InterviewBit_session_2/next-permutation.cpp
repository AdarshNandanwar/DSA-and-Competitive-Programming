// https://www.interviewbit.com/problems/next-permutation/

vector<int> Solution::nextPermutation(vector<int> &A) {
    // {val, index}
    set<pair<int, int>> s;
    int n = A.size();
    for(int i = n-1; i>=0; i--){
        auto it = s.upper_bound({A[i], -1});
        if(it == s.end()){
            s.insert({A[i], i});
        } else {
            int j = it->second;
            swap(A[i], A[j]);
            sort(A.begin()+i+1, A.end());
            return A;
        }
    }
    sort(A.begin(), A.end());
    return A;
}
