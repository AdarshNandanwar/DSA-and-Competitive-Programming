// https://leetcode.com/problems/string-compression-ii/description/

// Method 1 (2D DP, Recursive, O(n*k*n) time, O(n*k) space):

class Solution {

    int lengthForFreq(int freq){
        if(freq == 0){
            return 0;
        } else if(freq == 1){
            return 1;
        } else if(freq < 10){
            return 2;
        } else if(freq < 100){
            return 3;
        } else {
            // freq can't be more than 100 due to input constraints.
            return 4;
        }
    }

    // returns the min lenget of compressed string for s[index..n-1] with given cost.
    int helper(const string & s, int index, int cost, vector<vector<int>> & dp){
        int n = s.length();

        if(index >= s.length()){
            return 0;
        }

        if(dp[index][cost] != -1){
            return dp[index][cost];
        }

        /* 
        For every char in string s, it can be considered as a starting point
        for its type of char in the compressed string. To club chars of similar types,
        we need to make them contiguous by removing all other chars that come between them. 
        This will be our cost. Lets call this costToGroup.
        Eg. Assiminh inf cost, for aaa[aabccaab], the compressed string can be:
                a3[a2bc2a2b]
                a3[a2c2a2b]     rem 1
                a3[a2bca2b]     rem 1
                a3[a2bc2ab]     rem 1
                ...
                a3[a3a2b]       rem 3
                a3[a4ab]        rem 3
                a3[a5b]         rem 3
                a3[a5]
        Basically, we are checking length of compressed string starting at index
        with its count being 0,1,2,3,4,... till the cost runs out or the string ends.
        Lets assume s[i] is 'a'
        dp[i][j] = min(
            Length of compressed string of "" + dp[i+1][j-1],   // take s[i] 0 times
            Length of compressed string of "a" + dp[i+1][j],   // take s[i] 1 time
            Length of compressed string of "aa" + dp[indexOfLast'a'+1][j-costToGroup],   // take s[i] 2 times
            ...
        );
        */
        
        int minLen = INT_MAX;
        char letter = s[index];
        
        // Don't start the contiguous letter group at current index
        if(cost >= 1){
            minLen = min(minLen, helper(s, index+1, cost-1, dp));
        }
        
        int letterCount = 0, deletionNeededToGroup = 0;
        for(int i=index; i<n; i++){
            if(s[i] == letter){
                letterCount++;
            } else {
                deletionNeededToGroup++;
            }

            // contiguous group of length letterCount starts at current index
            if(deletionNeededToGroup > cost){
                break;
            }
            minLen = min(minLen, lengthForFreq(letterCount) + helper(s, i+1, cost-deletionNeededToGroup, dp));
        }

        return dp[index][cost] = minLen;
    }

public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return helper(s, 0, k, dp);
    }
};