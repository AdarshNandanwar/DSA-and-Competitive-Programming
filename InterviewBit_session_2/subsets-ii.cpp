// https://www.interviewbit.com/problems/subsets-ii/

void helper(vector<int> &A, int st, vector<int> &cur, vector<vector<int>> &ans){
    int n = A.size();
    ans.push_back(cur);
    if(st == n) return;
    for(int i = st; i<n; i++){
        if(i != st and A[i] == A[i-1]) continue;
        cur.push_back(A[i]);
        helper(A, i+1, cur, ans);
        cur.pop_back();
    }
}

vector<vector<int>> Solution::subsetsWithDup(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    vector<int> cur;
    helper(A, 0, cur, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
