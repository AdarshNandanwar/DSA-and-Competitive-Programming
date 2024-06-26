// https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/description/

// Method 1 (Counting, O(n*l)):

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        vector<int> freq(26, 0);
        for(auto & word:words){
            for(char c:word){
                freq[c-'a']++;
            }
        }
        for(int i=0; i<26; i++){
            if(freq[i]%n != 0){
                return false;
            }
        }
        return true;
    }
};