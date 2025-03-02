// https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/

// Method 1 (Backtracking, O(n!)):

class Solution {
    bool helper(int index, vector<bool> & used, vector<int> & ans, const int n){
        if(index == (2*n-1)){
            return true;
        }
        if(ans[index] != 0){
            return helper(index+1, used, ans, n);
        }

        for(int i=n; i>1; i--){
            if(used[i]){
                continue;
            }
            if(index+i >= 2*n-1 or ans[index+i] != 0){
                continue;
            }
            ans[index] = ans[index+i] = i;
            used[i] = true;
            if(helper(index+1, used, ans, n)){
                return true;
            }
            ans[index] = ans[index+i] = 0;
            used[i] = false;
        }
        if(!used[1]){
            ans[index] = 1;
            used[1] = true;
            if(helper(index+1, used, ans, n)){
                return true;
            }
            ans[index] = 0;
            used[1] = false;
        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<bool> used(n+1, false);
        vector<int> ans(2*n-1, 0);
        helper(0, used, ans, n);
        return ans;
    }
};
