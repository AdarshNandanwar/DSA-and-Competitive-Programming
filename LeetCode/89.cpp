// https://leetcode.com/problems/gray-code/

// Method 1

class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0) return {0};
        vector<int> h1 = grayCode(n-1), h2(h1.begin(), h1.end()), res;
        reverse(h2.begin(), h2.end());
        for(auto i:h1) res.push_back(i);
        for(auto i:h2) res.push_back((1<<(n-1))+i);
        return res;
    }
};

// Method 2

class Solution {
public:
    void helper(int n, int cur, bool firstOnes, vector<int> & ans){
        if(n == 0){
            ans.push_back(cur);
            return;
        }
        if(firstOnes){
            helper(n-1, cur+(1<<(n-1)), 0, ans);
            helper(n-1, cur, 1, ans);
        } else {
            helper(n-1, cur, 0, ans);
            helper(n-1, cur+(1<<(n-1)), 1, ans);
        }
    }
    
    vector<int> grayCode(int n) {
        vector<int> ans;
        helper(n, 0, 0, ans);
        return ans;
    }
};