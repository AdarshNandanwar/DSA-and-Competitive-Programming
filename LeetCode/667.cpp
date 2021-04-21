// https://leetcode.com/problems/beautiful-arrangement-ii/

//  Method 1 (Greedy):

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int lo = 1, hi = n;
        for(int i = 0; i<(k-1)/2; i++){
            ans.push_back(lo++);
            ans.push_back(hi--);
        }
        if(k%2){
            while(lo<=hi) ans.push_back(lo++);
            return ans;
        } else {
            while(n-ans.size() > 2) ans.push_back(lo++);
            ans.push_back(hi--);
            ans.push_back(lo++);
            return ans;
        }
    }
};