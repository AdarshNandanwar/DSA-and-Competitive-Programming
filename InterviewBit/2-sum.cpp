// https://www.interviewbit.com/problems/2-sum/

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    int n = A.size();
    unordered_map<int, int> index;
    for(int i = 0; i<n; i++){
        if(index.count(B-A[i])) return {index[B-A[i]]+1, i+1};
        if(!index.count(A[i])) index[A[i]] = i;
    }
    return {};
}
