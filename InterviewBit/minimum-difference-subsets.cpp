// https://www.interviewbit.com/problems/minimum-difference-subsets/

void helper(vector<int> &A, int index, int curSum, const int & sum, int & ans, vector<unordered_set<int>> & done){
    int n = A.size();
    if(index == n){
        ans = min(ans, abs(sum-curSum-curSum));
        return;
    }
    if(done[index].count(curSum)) return;
    done[index].insert(curSum);
    helper(A, index+1, curSum+A[index], sum, ans, done);
    helper(A, index+1, curSum, sum, ans, done);
}

int Solution::solve(vector<int> &A) {
    int sum = 0;
    for(auto i:A) sum += i;
    int ans = INT_MAX;
    vector<unordered_set<int>> done(A.size());
    helper(A, 0, 0, sum, ans, done);
    return ans;
}
