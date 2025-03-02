// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/

// Method 1 (istringstream, O(n)):

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = searchWord.size();
        int index = 1;
        istringstream iss(sentence);
        string word;
        while(getline(iss, word, ' ')){
            if(n > word.length()){
                index++;
                continue;
            }
            bool isPrefix = true;
            for(int i=0; i<n; i++){
                if(word[i] != searchWord[i]){
                    isPrefix = false;
                    break;
                }
            }
            if(isPrefix){
                return index;
            } else {
                index++;
            }
        }
        return -1;
    }
};
