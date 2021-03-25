// https://leetcode.com/problems/partition-labels/

// Method 1 (Greedy, O(n)):

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int n = S.length();
        if(n == 0) return {};
        vector<int> lastIndex(26, -1), res;
        for(int i = 0; i<n; i++) lastIndex[S[i]-'a'] = i;
        int cur = 0, curEnd = lastIndex[S[0]-'a'], prev = 0;
        while(cur<n){
            while(cur<n and cur<=curEnd) curEnd = max(curEnd, lastIndex[S[cur++]-'a']);
            res.push_back(cur-prev);
            if(cur == n) break;
            curEnd = lastIndex[S[cur]-'a'];
            prev = cur;
        }
        return res;
    }
};