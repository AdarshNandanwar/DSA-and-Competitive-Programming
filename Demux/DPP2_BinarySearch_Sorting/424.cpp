// https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length(), other = 0, p1, p2, ans = 0;
        // [p1, p2)
        unordered_set<int> characters;
        for(auto c:s) characters.insert(c);
        
        for(auto i:characters){
            p1 = p2 = other = 0;
            while(p2<n){
                if(s[p2] != i){
                    while(other >= k){
                        if(s[p1++] != i) other--;
                    }
                    other++;
                }
                p2++;
                ans = max(ans, p2-p1);
            }
        }
        return ans;
    }
};