// https://leetcode.com/problems/custom-sort-string/

// Method 1 (Custom Comparator, O(nlogn)):

class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> pos(26, 26);
        for(int i = 0; i<order.length(); i++) pos[order[i]-'a'] = i;
        sort(str.begin(), str.end(), [&pos](const char & a, const char & b){
            return pos[a-'a'] < pos[b-'a'];
        });
        return str;
    }
};