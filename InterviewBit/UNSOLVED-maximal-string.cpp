// https://www.interviewbit.com/problems/maximal-string/

// Method 1 (Greedy, O(n2)):

string Solution::solve(string A, int B) {
    int n = A.length(), maxInd;
    for(int i = 0; i<n and B>0; i++){
        char maxVal = A[i];
        for(int j = i+1; j<n; j++){
            if(maxVal < A[j]){
                maxVal = A[j];
                maxInd = j;
            }
        }
        if(maxVal > A[i]){
            swap(A[i], A[maxInd]);
            B--;
        } 
    }
    return A;
}

// Method 2 (Backtracking, O(n)):

string ans;
void helper(string A, int B, int start){
    if(A > ans) ans = A;
    if(B == 0) return;
    string s = A;
    int n = s.length();
    for(int i = start+1; i<n; i++){
        if(s[start] >= s[i]) continue;
        swap(s[start], s[i]);
        helper(s, B-1, start+1);
        swap(s[start], s[i]);
    }
}
string Solution::solve(string A, int B) {
    ans = A;
    helper(A, B, 0);
    return ans;
}
