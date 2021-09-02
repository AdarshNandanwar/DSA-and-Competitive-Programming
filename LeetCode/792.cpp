// https://leetcode.com/problems/number-of-matching-subsequences/

// Method 1 (Storing Index, Binary Search, O(n*k*logn)):

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