// https://leetcode.com/problems/longest-string-chain/

// Method 1 (Hash Map, O(n*l)):

bool cmp(const string & a, const string & b){
    return a.length() < b.length();
}

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        unordered_map<string, int> m;
        int res = 0;
        for(auto s:words){
            if(m.count(s)) continue;
            int mlen = 1;
            for(int i = 0; i<s.length(); i++){
                mlen = max(mlen, 1+m[s.substr(0, i)+s.substr(i+1)]);
            }
            m[s] = mlen;
            res = max(res, mlen);
        }
        return res;
    }
};

// Method 2 (1D DP, O(n2*l)):

class Solution {
    bool isPredecessor(const string & word1, const string & word2){
        // is word1 a predecessor of word2
        int n1 = word1.length(), n2 = word2.length(), p1 = 0, p2 = 0;
        if(n1+1 != n2){
            return false;
        }
        bool skipped = false;
        while(p1<n1 and p2<n2){
            if(word1[p1] == word2[p2]){
                p1++;
                p2++;
            } else if(!skipped){
                skipped = true;
                p2++;
            } else {
                return false;
            }
        }
        return true;
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size(), res;
        sort(words.begin(), words.end(), [](const string & a, const string & b){
            return a.length() < b.length();
        });
        // lsc[i] = longest word chain using words[0..i] ending at ith word
        vector<int> lsc(n, 1);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(isPredecessor(words[j], words[i])){
                    lsc[i] = max(lsc[i], 1+lsc[j]);
                }
            }
            res = max(res, lsc[i]);
        }
        return res;
    }
};