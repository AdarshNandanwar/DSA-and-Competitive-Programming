// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/

// Method 1 (Count, O(n) time, O(1) space):

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length(), ans = INT_MAX;
        
        int aCount = 0, bCount = 0;
        for(char c:s){
            if(c == 'a'){
                aCount++;
            } else {
                bCount++;
            }
        }

        // All 'b's after 'a's
        int aCumCount = 0, bCumCount = 0;
        for(int firstB = 0; firstB<n; firstB++){
            ans = min(ans, bCumCount + (aCount - aCumCount));
            if(s[firstB] == 'a'){
                aCumCount++;
            } else {
                bCumCount++;
            }
        }
        // Only 'b's
        ans = min(ans, bCount);

        return ans;
    }
};
