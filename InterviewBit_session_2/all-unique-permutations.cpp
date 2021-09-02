// https://www.interviewbit.com/problems/all-unique-permutations/

void helper(vector<int> &A, int index, vector<int> &cur, vector<vector<int>> &ans, vector<bool> &used){
    int n = A.size();
    if(index == n){
        ans.push_back(cur);
        return;
    }
    unordered_set<int> s;
    for(int i = 0; i<n; i++){
        if(used[i] or s.count(A[i])) continue;
        used[i] = 1;
        cur.push_back(A[i]);
        s.insert(A[i]);
        helper(A, index+1, cur, ans, used);
        used[i] = 0;
        cur.pop_back();
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> ans;
    vector<int> cur;
    vector<bool> used(A.size(), 0);
    helper(A, 0, cur, ans, used);
    return ans;
}
