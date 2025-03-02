// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/

// Method 1 (XOR + Bit Mask, O(n) time, O(n) space):

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.length();

        unordered_set<char> vowels;
        vowels.insert('a');
        vowels.insert('e');
        vowels.insert('i');
        vowels.insert('o');
        vowels.insert('u');

        int longestSubstring = 0;
        unordered_map<int, int> lastOccurence;
        lastOccurence[0] = n;
        vector<int> suffixXor(n+1);
        for(int i=n-1; i>=0; i--){
            int mask = 0;
            if(vowels.count(s[i])){
                mask = (1<<(s[i]-'a'));
            }
            suffixXor[i] = (mask ^ suffixXor[i+1]);
            if(lastOccurence.count(suffixXor[i])){
                longestSubstring = max(longestSubstring, lastOccurence[suffixXor[i]] - i);
            } else {
                lastOccurence[suffixXor[i]] = i;
            }
        }

        return longestSubstring;
    }
};
