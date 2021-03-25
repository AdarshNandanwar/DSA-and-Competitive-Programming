// https://www.interviewbit.com/problems/combinations/

void helper(int A, int B, int st, vector<int> & cur, vector<vector<int>> & ans){
    if(B == 0){
        ans.push_back(cur);
        return;
    }
    for(int i = st; i<=A; i++){
        cur.push_back(i);
        helper(A, B-1, i+1, cur, ans);
        cur.pop_back();
    }
}

vector<vector<int> > Solution::combine(int A, int B) {
    vector<vector<int>> ans;
    vector<int> cur;
    helper(A, B, 1, cur, ans);
    return ans;
}
