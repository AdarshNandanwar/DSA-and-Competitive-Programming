// https://leetcode.com/problems/shifting-letters/

// Method 1 (suffix sum, O(n)):

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        shifts.push_back(0);
        for(int i = n-1; i>=0; i--){
            shifts[i] = (shifts[i]+shifts[i+1])%26;
            s[i] = 'a' + (shifts[i]+s[i]-'a')%26;
        }
        return s;
    }
};