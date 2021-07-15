// https://www.interviewbit.com/problems/subset/

void helper(vector<int> & A, int index, vector<int> & cur, vector<vector<int>> & ans){
    if(index == A.size()){
        ans.push_back(cur);
        return;
    } 
    helper(A, index+1, cur, ans);
    cur.push_back(A[index]);
    helper(A, index+1, cur, ans);
    cur.pop_back();
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    vector<int> cur;
    helper(A, 0, cur, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
