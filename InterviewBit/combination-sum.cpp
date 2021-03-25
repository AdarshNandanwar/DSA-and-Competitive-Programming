// https://www.interviewbit.com/problems/combination-sum/

void helper(vector<int> &A, int B, int st, vector<int> & cur, vector<vector<int>> & ans){
    int n = A.size();
    if(B == 0){
        ans.push_back(cur);
        return;
    }
    if(B<0 or st == n) return;
    for(int i = st; i<n; i++){
        if(A[i] == 0 or (i != st and A[i] == A[i-1])) continue;
        cur.push_back(A[i]);
        helper(A, B-A[i], i, cur, ans);
        cur.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<int> cur;
    vector<vector<int>> ans;
    sort(A.begin(), A.end());
    helper(A, B, 0, cur, ans);
    return ans;
}
