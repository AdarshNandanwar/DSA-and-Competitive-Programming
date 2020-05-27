// https://leetcode.com/problems/unique-binary-search-trees/

class Solution {
public:
    
    unordered_map<int, int> m;
    
    int numTrees(int n) {
        if(n == 0 || n == 1) return 1;
        if(m.find(n) != m.end()) return m[n];
        int ans = 0;
        for(int i =0; i<n; i++){
            ans += (numTrees(i)*numTrees(n-i-1));
        }
        m[n] = ans;
        return ans;
    }
};