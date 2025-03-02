// https://leetcode.com/problems/most-beautiful-item-for-each-query/

// Method 1 (Ordered Map, O(nlogn + mlogn)):

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int, int> maxBeautyForPrice;
        for(vector<int> & item:items){
            maxBeautyForPrice[item[0]] = max(maxBeautyForPrice[item[0]], item[1]);
        }
        int curMaxBeauty = 0;
        for(auto itr:maxBeautyForPrice){
            curMaxBeauty = max(curMaxBeauty, itr.second);
            maxBeautyForPrice[itr.first] = curMaxBeauty;
        }

        int m = queries.size();
        vector<int> res(m);
        for(int i=0; i<m; i++){
            auto ub = maxBeautyForPrice.upper_bound(queries[i]);
            if(ub == maxBeautyForPrice.begin()){
                res[i] = 0;
            } else {
                res[i] = prev(ub)->second;
            }
        }

        return res;
    }
};
