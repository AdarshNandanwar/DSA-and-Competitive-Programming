// https://www.interviewbit.com/problems/subset/

void helper(vector<int> &A, int st, vector<int> & cur, vector<vector<int>> & ans){
    ans.push_back(cur);
    int n = A.size();
    if(st == n) return;
    for(int i = st; i<n; i++){
        cur.push_back(A[i]);
        helper(A, i+1, cur, ans);
        cur.pop_back();
    }
}

vector<vector<int>> Solution::subsets(vector<int> &A) {
    vector<vector<int>> ans;
    vector<int> cur;
    sort(A.begin(), A.end());
    helper(A, 0, cur, ans);
    return ans;
}
