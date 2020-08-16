// https://leetcode.com/problems/distribute-candies/

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> s;
        for(auto i:candies) s.insert(i);
        return min(candies.size()/2, s.size());
    }
};