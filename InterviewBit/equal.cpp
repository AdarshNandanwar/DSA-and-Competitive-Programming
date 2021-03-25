// https://www.interviewbit.com/problems/equal/

// Method 1 (Hast Table, O(n2)):

vector<int> Solution::equal(vector<int> &A) {
    int n = A.size();
    vector<int> res;
    unordered_map<long, pair<int, int>> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            if(m.count(A[j]+A[i])){
                auto lhs = m[A[j]+A[i]];
                if(lhs.first < j and lhs.second != j and lhs.second != i){
                    if(res.empty()) res = {lhs.first, lhs.second, j, i};
                    else res = min(res, {lhs.first, lhs.second, j, i});
                }
            } else {
                m[A[j]+A[i]] = make_pair(j, i);
            }
        }
    }
    return res;
}
