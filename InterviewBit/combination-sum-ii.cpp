// https://www.interviewbit.com/problems/combination-sum-ii/

void helper(vector<int> &A, int B, int start, vector<int> & cur, vector<vector<int>> & ans){
    if(B == 0){
        ans.push_back(cur);
        return;
    }
    if(B<0) return;
    
    for(int i = start; i<A.size(); i++){
        if(i != start and A[i] == A[i-1]) continue;
        cur.push_back(A[i]);
        helper(A, B-A[i], i+1, cur, ans);
        cur.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    vector<int> cur;
    helper(A, B, 0, cur, ans);
    return ans;
}