// https://leetcode.com/problems/maximum-units-on-a-truck/

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int> & a, const vector<int> & b){
            return a[1] > b[1];
        });
        int res = 0;
        for(auto &i:boxTypes){
            int count = min(truckSize, i[0]);
            truckSize -= count;
            res += (count*i[1]);
            if(truckSize == 0) return res;
        }
        return res;
    }
};