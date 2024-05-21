// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

// Method 1 (Brute Force, Bit Manipulation, O(2^n)):

class Solution {

    // Returns bitmask of string s if all characters are unique, else, -1
    int getBitMask(const string& s){
        int mask = 0;
        for(const char c:s){
            int newBit = (1<<(c-'a'));
            if((newBit & mask) != 0){
                return -1;
            }
            mask |= newBit;
        }
        return mask;
    }

    int getMaskLength(int mask){
        int len = 0;
        while(mask){
            if(mask & 1){
                len++;
            }
            mask >>= 1;
        }
        return len;
    }

    // Max new characters you can add from startIndex with curMask characters already added.
    int getMaxLength(const vector<int>& arrMasks, int startIndex, int& curMask){
        int n = arrMasks.size();
        if(startIndex == n){
            return 0;
        }

        int res = 0;
        for(int i = startIndex; i < n; i++){
            if((curMask & arrMasks[i]) == 0){
                curMask ^= arrMasks[i];
                res = max(res, getMaskLength(arrMasks[i]) + getMaxLength(arrMasks, i+1, curMask));
                curMask ^= arrMasks[i];
            }
        }
        return res;
    }
public:
    int maxLength(vector<string>& arr) {
        vector<int> arrMasks; // bitmask
        for(const string& s:arr){
            int mask = getBitMask(s);
            if(mask != -1){
                arrMasks.push_back(mask);
            }
        }
        int currentMask = 0;
        return getMaxLength(arrMasks, 0, currentMask);
    }
};

// Alternate Code:

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