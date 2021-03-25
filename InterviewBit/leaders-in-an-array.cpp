// https://www.interviewbit.com/problems/leaders-in-an-array/

vector<int> Solution::solve(vector<int> &A) {
    vector<int> res;
    int rightMax = INT_MIN;
    for(int i = A.size()-1; i>=0; i--){
        if(A[i] > rightMax) res.push_back(A[i]);
        rightMax = max(rightMax, A[i]);
    }
    return res;
}
