// https://leetcode.com/problems/numbers-at-most-n-given-digit-set/

// Method 1 (Digit DP, Bottom Up):

class Solution {
public:
    
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        
        string s = to_string(N);
        int n = D.size(), l = s.length();
        
        // dp[i][0]: no. of ways of [0..i] if [0..i] is less than s[0..i]
        // dp[i][1]: no. of ways of [0..i] if [0..i] is equal to s[0..i]
        vector<vector<int>> dp(l, vector<int>(2));
        
        // base case
        dp[0][0] = lower_bound(D.begin(), D.end(), string(1, s[0]))-D.begin();
        dp[0][1] = binary_search(D.begin(), D.end(), string(1, s[0]));
        
        for(int i = 1; i<l; i++){
            int lb = lower_bound(D.begin(), D.end(), string(1, s[i]))-D.begin();
            // +n for the case when [0..i-1] is all 0
            dp[i][0] = n + dp[i-1][0]*n + dp[i-1][1]*lb;
            dp[i][1] = dp[i-1][1]*binary_search(D.begin(), D.end(), string(1, s[i]));
        }
        
        return dp[l-1][0]+dp[l-1][1];
    }
};

// Method 1 (Digit DP, Top Down):

class Solution {
public:
    
    int atMostNGivenDigitSetHelper(vector<string>& D, string& s, int index, bool isPrevEqual, vector<vector<int>> & dp){

        int n = D.size(), lessCount = 0, res = 0;
        
        // base case
        if(index >= s.length()){
            return 1;
        }
        
        if(dp[index][isPrevEqual] != -1){
            return dp[index][isPrevEqual];
        }
        
        if(!isPrevEqual){
            res = n*atMostNGivenDigitSetHelper(D, s, index+1, false, dp);
        } else {
            for(int i = 0; i<n; i++){
                if(D[i][0] < s[index]){
                    lessCount++;
                } else if(D[i][0] == s[index]){
                    res += atMostNGivenDigitSetHelper(D, s, index+1, true, dp);
                } else {
                    break;
                }
            }
            res += (lessCount*atMostNGivenDigitSetHelper(D, s, index+1, false, dp));
        }
        
        return dp[index][isPrevEqual] = res;
    }
    
    
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        string s = to_string(N);
        int n = s.length(), res = 0;
        
        for(int i = 1; i<n; i++){
            res += pow(D.size(), i);
        }
        
        // dp[i][0] = num of combinations of valid [i..n] digits when [1..i-1] is not equal
        // dp[i][1] = num of combinations of valid [i..n] digits when [1..i-1] is equal
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        res += atMostNGivenDigitSetHelper(D, s, 0, true, dp);
        
        return res;
    }
};

// Method 1 (Digit DP, Bottom Up):

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        string s = to_string(N);
        int n = s.length(), m = D.size(), res = 0;
        bool isEqualPrev, isEqual;
        
        for(int i = 1; i<n; i++){
            res += pow(m, i);
        }
        
        // isEqual = tells if it is possible to make i most significant digits equal
        // dp[i] = num of combinations of i most significant digits which are less than those of N
        vector<int> dp(n+1);
        
        // base case
        dp[0] = 0;
        isEqual = true;
        
        for(int i = 1; i<=n; i++){
            isEqualPrev = isEqual;
            isEqual = false;
            int lessCount = 0;
            for(int j=0; j<m; j++){
                if(D[j][0] > s[i-1]){
                    break;
                } else if (D[j][0] == s[i-1] and isEqualPrev){
                    isEqual = true;
                } else {
                    lessCount++;
                }
            }
            dp[i] = m*dp[i-1] + lessCount*isEqualPrev;
        }
        
        return res+dp[n]+isEqual;
    }
};