// https://www.interviewbit.com/problems/shortest-common-superstring/

// Method 1 (TLE, Brute Force, O(n!)):

string combine(string & a, string & b){
    int n = a.length(), m = b.length(), i, j;
    for(i = 0; i<n; i++){
        for(j = 0; j<m and i+j<n; j++){
            if(a[i+j] != b[j]) break;
        }
        if(i+j == n) return a+b.substr(n-i);
        if(j == m) return a;
    }
    return a+b;
}

void helper(vector<string> &A, int index, string cur, vector<bool> & visited, int & ans){
    int n = A.size();
    if(index == n){
        ans = min(ans, (int)cur.length());
        return;
    }
    
    string temp;
    int res = INT_MAX;
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            visited[i] = 1;
            helper(A, index+1, combine(cur, A[i]), visited, ans);
            visited[i] = 0;
        }
    }
}

int Solution::solve(vector<string> &A) {
    
    int n =A.size();
    if(n == 0) return 0;
    if(n == 1) return A[0].length();
    
    vector<bool> visited(n, 0);
    string cur = "";
    int ans = INT_MAX;
    helper(A, 0, cur, visited, ans);
    return ans;
}
