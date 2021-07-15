// https://www.interviewbit.com/problems/permutations/

void helper(vector<int> &A, int index, vector<int> &cur, vector<vector<int>> &ans, vector<bool> &used){
    int n = A.size();
    if(n == index){
        ans.push_back(cur);
        return;
    }
    for(int i = 0; i<n; i++){
        if(used[i]) continue;
        used[i] = 1;
        cur.push_back(A[i]);
        helper(A, index+1, cur, ans, used);
        used[i] = 0;
        cur.pop_back();
    }
}

vector<vector<int>> Solution::permute(vector<int> &A) {
    int n = A.size();
    vector<vector<int>> ans;
    vector<int> cur;
    vector<bool> used(n, 0);
    helper(A, 0, cur, ans, used);
    return ans;
}
