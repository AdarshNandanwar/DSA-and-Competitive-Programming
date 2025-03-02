// https://leetcode.com/problems/find-unique-binary-string/

// Method 1 (Brute Force, Hash Set, O(n)):

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        
        unordered_set<int> s;
        for(const string & num:nums){
            int val = 0;
            for(int i=0; i<n; i++){
                val <<= 1;
                val |= (num[i] - '0');
            }
            s.insert(val);
        }
        int resVal = 0;
        while(s.count(resVal)){
            resVal++;
        }
        
        string res(n, '0');
        for(int i=0; i<n; i++){
            res[n-1-i] = '0' + ((resVal>>i)&1);
        }
        return res;
    }
};
