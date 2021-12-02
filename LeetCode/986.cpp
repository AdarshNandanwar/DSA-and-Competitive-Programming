// https://leetcode.com/problems/interval-list-intersections/

// Method 1 (2 pointers, O(n1+n2)):

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int n1 = firstList.size(), n2 = secondList.size(), p1 = 0;
        for(int p2 = 0; p2<n2; p2++){
            while(p1<n1 and firstList[p1][0] <= secondList[p2][1]){
                int st = max(firstList[p1][0], secondList[p2][0]);
                int end = min(firstList[p1][1], secondList[p2][1]);
                if(st<=end) res.push_back({st, end});
                p1++;
            }
            if(p1-1>=0) p1--;
        }
        return res;
    }
};