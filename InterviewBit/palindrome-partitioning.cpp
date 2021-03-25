// https://www.interviewbit.com/problems/palindrome-partitioning/

bool isPalindrome(string & s, int st, int end, vector<vector<int>> & dp){
    
    if(dp[st][end] != -1) return dp[st][end];
    
    // inclusive
    int n = end-st+1;
    if(n%2){
        // odd
        int mid = st+(end-st)/2;
        for(int i = 0; i<=n/2; i++){
            if(s[mid-i] != s[mid+i]) return dp[st][end] = false;
        }
    } else {
        // even
        int mid = st+(end-st)/2;
        for(int i = 0; i<n/2; i++){
            if(s[mid-i] != s[mid+i+1]) return dp[st][end] = false;
        }
    }
    return dp[st][end] = true;
}

void helper(string & A, int st, vector<string> & cur, vector<vector<string> > & ans, int & n, vector<vector<int>> & dp){
    
    if(st == n){
        ans.push_back(cur);
        return;
    }
    
    for(int i = st; i<n; i++){
        if(isPalindrome(A, st, i, dp)){
            cur.push_back(A.substr(st, i-st+1));
            helper(A, i+1, cur, ans, n, dp);
            cur.pop_back();
        }
    }
}

vector<vector<string> > Solution::partition(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    
    int n = A.size();
    vector<vector<int>> dp(n+1, vector(n+1, -1));
    vector<vector<string> > ans;
    vector<string> cur;
    helper(A, 0, cur, ans, n, dp);
    return ans;
}
