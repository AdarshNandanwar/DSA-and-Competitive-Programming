// https://leetcode.com/problems/maximum-units-on-a-truck/

// Method 1 (Bucket Sort, O(n)):

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<int> buckets(1001, 0);
        for(auto &boxType:boxTypes){
            buckets[boxType[1]] += boxType[0];
        }
        int units = 0, qty;
        for(int i=1000; i>=0; i--){
            qty = min(truckSize, buckets[i]);
            units += qty*i;
            truckSize -= qty;
        }
        return units;
    }
};

// Method 2 (Sorting Greedy, O(nlogn)):

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