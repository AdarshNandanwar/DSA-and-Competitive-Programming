// https://leetcode.com/problems/longest-palindromic-substring/

// Method 1 (2 Pointer, O(n2)):

class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0, n = s.length(), left, right, len, maxLeft = 0;
        for(int mid=0; mid<n; mid++){
            // odd length
            left = mid;
            right = mid;
            while(left>=0 and right<n and s[left] == s[right]){
                left--;
                right++;
            }
            len = right-left-1;
            if(len > maxLen){
                maxLen = len;
                maxLeft = left+1;
            }
            
            // even length
            left = mid;
            right = mid+1;
            while(left>=0 and right<n and s[left] == s[right]){
                left--;
                right++;
            }
            len = right-left-1;
            if(len > maxLen){
                maxLen = len;
                maxLeft = left+1;
            }
        }
        return s.substr(maxLeft, maxLen);
    }
};

// Method 2 (2D DP, O(n2)):

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), maxLen = 1, start = 0;
        // dp[i][j] = is [i, j) palindrome
        vector<vector<bool>> dp(n+1, vector<bool>(n+1, true));
        for(int i=n-1; i>=0; i--){
            for(int j=i+2; j<=n; j++){
                dp[i][j] = (s[i] == s[j-1]) and dp[i+1][j-1];
                if(dp[i][j] and j-i>maxLen){
                    maxLen = j-i;
                    start = i;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};