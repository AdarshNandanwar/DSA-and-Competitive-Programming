// https://www.interviewbit.com/problems/first-repeating-element/

// Method 1 (hash table, O(n) time, O(n) space):

int Solution::solve(vector<int> &A) {
    int res = -1;
    unordered_set<int> s;
    for(int i = A.size()-1; i>=0; i--){
        if(s.count(A[i])) res = A[i];
        else s.insert(A[i]);
    } 
    return res;
}
