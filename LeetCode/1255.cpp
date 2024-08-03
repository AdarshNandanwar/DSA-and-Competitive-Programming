// https://leetcode.com/problems/maximum-score-words-formed-by-letters/

// Method 1 (Backtracking, O(2^n)):

class Solution {
    int getScore(const string & word, const vector<int>& score){
        int n = word.length();
        int res = 0;
        for(int i=0; i<n; i++){
            res += score[word[i]-'a'];
        }
        return res;
    }
    bool addWord(const string & word, vector<int>& freq){
        int n = word.length();
        int i = 0;
        while(i<n){
            if(freq[word[i]-'a'] == 0){
                break;
            }
            freq[word[i]-'a']--;
            i++;
        }

        if(i==n){
            return true;
        }

        i--;
        while(i>=0){
            freq[word[i]-'a']++;
            i--;
        }
        return false;
    }
    void removeWord(const string & word, vector<int>& freq){
        int n = word.length();
        int i = 0;
        while(i<n){
            freq[word[i]-'a']++;
            i++;
        }
    }
    int helper(const vector<string>& words, vector<int>& freq, const vector<int>& score, int index){
        int n = words.size();
        if(index == n){
            return 0;
        }
        int res = helper(words, freq, score, index+1);
        bool success = addWord(words[index], freq);
        if(success){
            res = max(res, getScore(words[index], score) + helper(words, freq, score, index+1));
            removeWord(words[index], freq);
        }
        return res;
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26);
        for(int i=0; i<letters.size(); i++){
            freq[letters[i]-'a']++;
        }
        return helper(words, freq, score, 0);
    }
};
