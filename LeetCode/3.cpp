// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Method 1 (2 Pointer, Sliding Window, O(n)):

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> used(128, false);
        // [left, right)
        int left = 0, right = 0, n = s.length(), res = 0;
        while(right < n){
            while(used[s[right]]){
                used[s[left]] = false;
                left++;
            }
            used[s[right]] = true;
            right++;
            res = max(res, right-left);
        }
        return res;
    }
};

// Alternate Code:

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), ans = 0;
        int p1 = 0, p2 = 0;
        vector<int> freq(256, 0);
        while(p2<n){
            while(freq[s[p2]]){
                freq[s[p1]]--;
                p1++;
            }
            freq[s[p2]]++;
            ans = max(ans, p2-p1+1);
            p2++;
        }
        return ans;
    }
};