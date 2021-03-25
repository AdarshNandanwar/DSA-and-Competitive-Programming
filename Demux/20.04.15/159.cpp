// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
// Same as:
// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

// 159. Longest Substring with At Most Two Distinct Characters
// Medium

// Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.

// Example 1:

// Input: "eceba"
// Output: 3
// Explanation: t is "ece" which its length is 3.
// Example 2:

// Input: "ccaabbb"
// Output: 5
// Explanation: t is "aabbb" which its length is 5.

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int k = 2;
        int len = s.length();
        if(len == 0 || k == 0){
            return 0;
        }
        unordered_map<int, int> m;
        int  p1 = 0, p2 = 0, curr_k = 0, max_len = 0;
        while(p2 < len){
            if(m[s[p2]] == 0){
                if(curr_k == k){
                    m[s[p1]]--;
                    if(m[s[p1]] == 0){
                        curr_k--;
                    }
                    p1++;
                } else {
                    curr_k++;
                    m[s[p2]]++;
                    p2++;
                }
            } else if(m[s[p2]] > 0){
                m[s[p2]]++;
                p2++;
            }
            if(curr_k <= k){
                max_len = max(max_len, p2-p1);
            }
        }
        return max_len;
    }
};