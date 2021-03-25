// https://leetcode.com/problems/palindrome-partitioning-ii/

// Method 1 (Precalculation of lengths, O(n2)):

class Solution {
public:
    int minCut(string s) {
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
};

// Method 2 (O(n3)):

class Solution {
public:
    
    bool isPalindrome(string s){
        int n = s.length();
        for(int i = 0; i<n/2; i++){
            if(s[i] != s[n-1-i])    
                return false;
        }
        return true;
    }
    
    int minCut(string s) {
        int n = s.length();
        if(n == 0) return 0;
        vector<int> dp(n+1);
        for(int i =0; i<=n; i++){
            dp[i] = n-i-1;
        }
        for(int i=n-1; i>=0; i--){
            string curr = "";
            for(int j=i; j<n; j++){
                curr += s[j];
                if(isPalindrome(curr)){
                    if(j+1<n)
                        dp[i] = min(dp[i], 1+dp[j+1]);
                    else
                        dp[i] = 0;
                }
            }
        }
        return dp[0];
    }
};