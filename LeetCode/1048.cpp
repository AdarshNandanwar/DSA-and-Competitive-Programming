// https://leetcode.com/problems/longest-string-chain/

// Method 1 (DP?):

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