// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/

// Method 1 (Counting, O(n+m)):

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26, 0);
        for(char c:s){
            freq[c-'a']++;
        }
        for(char c:t){
            freq[c-'a']--;
        }

        int steps = 0;
        for(int i:freq){
            steps += abs(i);
        }
        return steps/2;
    }
};
