// https://www.interviewbit.com/problems/palindrome-partitioning-ii/

// O(n2):

int Solution::minCut(string s) {
        int n = s.size();
        if(n<=1) return 0;
        vector<int> dp(n+1, n-1);
        // palindrome[i]: length of palindrome starting at i
        vector<unordered_set<int>> palindrome(n, {1});  
        
        for(int i = 0; i<n; i++){
            // odd
            for(int j = 0;;j++){
                if(i-j>=0 and i+j<n and s[i-j] == s[i+j]) palindrome[i-j].insert(2*j+1);
                else break;
            }
            // even
            for(int j = 0;;j++){
                if(i-j>=0 and i+j+1<n and s[i-j] == s[i+j+1]) palindrome[i-j].insert(2*(j+1));
                else break;
            }
        }
        
        // base case
        dp[n] = -1;
        
        for(int i = n-1; i>=0; i--) 
            for(auto j:palindrome[i])
                dp[i] = min(dp[i], dp[i+j]+1);
        
        return dp[0];
}

// O(n3):

bool isPalindrome(string & A, int st, int end){
    while(st<end) if(A[st++] != A[end--]) return 0;
    return 1;
}
int Solution::minCut(string A) {
    int n = A.size();
    if(n<=1) return 0;
    vector<int> dp(n+1, n-1);
    // base case
    dp[n] = -1;
    for(int i = n-1; i>=0; i--){
        for(int j = i; j<n; j++){
            if(isPalindrome(A, i, j)) dp[i] = min(dp[i], dp[j+1]+1);
        }
    }
    return dp[0];
}
