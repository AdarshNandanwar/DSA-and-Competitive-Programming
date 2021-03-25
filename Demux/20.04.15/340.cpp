// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

// 340. Longest Substring with At Most K Distinct Characters
// Hard

// Given a string, find the length of the longest substring T that contains at most k distinct characters.

// Example 1:

// Input: s = "eceba", k = 2
// Output: 3
// Explanation: T is "ece" which its length is 3.
// Example 2:

// Input: s = "aa", k = 1
// Output: 2
// Explanation: T is "aa" which its length is 2.



class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
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