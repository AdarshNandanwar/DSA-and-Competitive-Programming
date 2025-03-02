// https://leetcode.com/problems/circular-sentence/

// Method 1 (Loop, O(n)):

class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.length();
        for(int i=0; i<n; i++){
            if(sentence[i] == ' '){
                if(sentence[i-1] != sentence[i+1]){
                    return false;
                }
            }
        }
        return sentence[0] == sentence[n-1];
    }
};
