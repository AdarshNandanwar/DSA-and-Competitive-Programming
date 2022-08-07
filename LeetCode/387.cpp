// https://leetcode.com/problems/first-unique-character-in-a-string/

// Method 1 (O(n)):

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        vector<int> freq(26, 0);
        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
        } 
        char target = '#';
        for(int i=0; i<n; i++){
            if(freq[s[i]-'a'] == 1){
                target = s[i];
                break;
            }
        }
        for(int i=0; i<n; i++){
            if(s[i] == target){
                return i;
            }
        }
        return -1;
    }
};