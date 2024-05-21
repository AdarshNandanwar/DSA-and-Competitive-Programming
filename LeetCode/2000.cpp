// https://leetcode.com/problems/reverse-prefix-of-word/

// Method 1 (Loop, O(n)):

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = -1;
        int n = word.size();
        for(int i=0; i<n; i++){
            if(word[i] == ch){
                index = i+1;
                break;
            }
        }
        if(index > 0){
            reverse(word.begin(), word.begin()+index);
        }
        return word;
    }
};
