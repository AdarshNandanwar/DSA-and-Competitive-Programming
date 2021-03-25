// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& A) {
        int n = A.size(), j;
        if(n == 0) return "";
        if(n == 1) return A[0];
        string prefix = "";
        for(int i = 0; ; i++){
            for(j = 1; j<n; j++) if(i >= A[j].length() or A[j][i] != A[j-1][i]) break;
            if(j == n) prefix.push_back(A[0][i]);
            else break;
        }
        return prefix;
    }
};