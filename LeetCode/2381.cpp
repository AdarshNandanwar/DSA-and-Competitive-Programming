// https://leetcode.com/problems/shifting-letters-ii/

// Method 1 (Range Sum using Prefix Sum, O(n) time, O(n) space):

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();

        vector<int> delta(n+1);
        for(auto & shift:shifts){
            if(shift[2] == 0){
                shift[2] = -1;
            }
            delta[shift[0]] += shift[2];
            delta[shift[1]+1] -= shift[2];
        }

        for(int i=1; i<=n; i++){
            delta[i] += delta[i-1];
        }

        for(int i=0; i<n; i++){
            s[i] = ((((s[i] - 'a' + delta[i]) % 26) + 26) % 26) + 'a';
        }

        return s;
    }
};
