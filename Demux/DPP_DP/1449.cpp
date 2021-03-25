// https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/

bool cmp(const vector<int> & a, const vector<int> & b){
    int sa = accumulate(a.begin(), a.end(), 0), sb = accumulate(b.begin(), b.end(), 0);
    if(sa == sb){
        for(int i = 8; i>=0; i--){
            if(a[i] != b[i]) return a[i] < b[i];
        }
    } else {
        return sa < sb;
    }
    return true;
}

class Solution {
public:
    
    vector<int> helper(vector<int>& cost, int target, vector<vector<int>> & dp){
        
        if(target == 0) return vector<int>(9, 0);
        
        if(dp[target].size()) return dp[target];
        
        vector<int> res(1,-1);  // no solution
        for(int i = 0; i<9; i++){
            if(target - cost[i] >= 0) {
                auto h = helper(cost, target - cost[i], dp);
                if(h[0] != -1){
                    h[i]++;
                    if(cmp(res, h)) res = h;
                }
            }
        }
        return dp[target] = res;
    }
    
    string largestNumber(vector<int>& cost, int target) {
        vector<vector<int>> dp(target+1);
        auto h = helper(cost, target, dp);
        if(h[0] == -1) return "0";
        string ans = "";
        for(int i = 8; i>=0; i--){
            ans += string(h[i], i+'1');
        }
        return ans;
    }
};