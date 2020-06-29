// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

class Solution {
public:
    void mergeArrays(vector<pair<int, int>> & v, int st, int mid, int en, vector<int> & ans){
        int p1 = st, p2 = mid+1;
        vector<pair<int, int>> temp;
        while(p1<=mid and p2<=en){
            while(p2<=en and v[p1]>v[p2]){
                temp.push_back(v[p2++]);
            } 
            ans[v[p1].second] += (p2-mid-1);
            temp.push_back(v[p1++]);
        } 
        while(p1<=mid){
            ans[v[p1].second] += (p2-mid-1);
            temp.push_back(v[p1++]);
        }
        while(p2<=en){
            temp.push_back(v[p2++]);
        }
        int ind = 0;
        for(int i = st; i<=en; i++){
            v[i] = temp[ind++];
        }
    }

    void countInversion(vector<pair<int, int>> & v, int st, int en, vector<int> & ans){
        if(en-st<=0) return;
        int mid = st+(en-st)/2;
        countInversion(v, st, mid, ans);
        countInversion(v, mid+1, en, ans);
        mergeArrays(v, st, mid, en, ans);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<pair<int, int>> numsPair;
        for(int i = 0; i<n; i++){
            numsPair.push_back({nums[i], i});
        }
        countInversion(numsPair, 0, n-1, ans);
        return ans;
    }
};