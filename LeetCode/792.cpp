// https://leetcode.com/problems/number-of-matching-subsequences/

// Method 1 (Precomputation, O(len(s)+n*k)):

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.length();
        // nextPos[i][c] = index of the next occurance of char c after index i in string s
        vector<vector<int>> nextPos(n+1, vector<int>(26, n));
        for(int i=n-1; i>=0; i--){
            nextPos[i] = nextPos[i+1];
            nextPos[i][s[i]-'a'] = i;
        }
        int subsequences = 0;
        for(auto & word:words){
            int pos = 0, i;
            for(i=0; i<word.size(); i++){
                pos = nextPos[pos][word[i]-'a'];
                if(pos>=n){
                    break;
                }
                pos++;
            }
            if(i == word.size()){
                subsequences++;
            }
        }
        return subsequences;
    }
};

// Method 2 (Storing Index, Binary Search, O(n*k*logn)):

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.length(), res = 0, pos, flag;
        vector<vector<int>> v(26, vector<int>(0));
        for(int i = 0; i<n; i++){
            v[s[i]-'a'].push_back(i);
        }
        for(auto & word:words){
            pos = -1;
            flag = 0;
            for(auto & c:word){
                auto it = upper_bound(v[c-'a'].begin(), v[c-'a'].end(), pos);
                if(it == v[c-'a'].end()){
                    flag = 1;
                    break;
                }
                pos = *it;
            }
            if(flag) continue;
            res++;
        }
        return res;
    }
};