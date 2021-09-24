// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

// Method 1 (Brute Force, Bit Manipulation, O(2^n)):

class Solution {
public:
    
    int helper(vector<int> &v, int st, int mask){
        int n = v.size(), res = 0;
        if(st >= n){
            int cur = mask;
            while(cur){
                res += (cur&1);
                cur = (cur>>1);
            }
            return res;
        }
        res = max(res, helper(v, st+1, mask));
        if((v[st]&mask) == 0) res = max(res, helper(v, st+1, v[st]|mask));
        return res;
    }
    
    int maxLength(vector<string>& arr) {
        vector<int> v;
        // converting the strings to bit encoded integers
        for(auto &s:arr){
            int encode = 0;
            bool flag = 0;
            for(auto &c:s){
                int index = c-'a';
                if((encode>>index) & 1){
                    // skipping strings with repeated characters
                    flag = 1;
                    break;
                }
                encode |= (1<<index);
            }
            if(!flag) v.push_back(encode);
        }
        return helper(v, 0, 0);
    }
};