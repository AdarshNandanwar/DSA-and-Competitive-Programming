// https://leetcode.com/problems/jump-game-iii/

class Solution {
public:
    
    bool helper(vector<int> & arr, int cur){
        int n = arr.size();
        if(cur<0 or n<=cur) return 0;
        if(arr[cur] == -1) return 0;    // check visited
        if(arr[cur] == 0) return 1;
        int dist = arr[cur];
        arr[cur] = -1;                  // mark visited
        bool res = 0;
        res = res or helper(arr, cur-dist);
        res = res or helper(arr, cur+dist);
        return res;
    }
    
    bool canReach(vector<int>& arr, int start) {
        return helper(arr, start);
    }
};