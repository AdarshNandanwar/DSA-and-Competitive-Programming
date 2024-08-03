// https://leetcode.com/problems/sort-the-people/

// Method 1 (Sorting, O(nlogn) time, O(n) space):

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, string>> data(n);
        for(int i=0; i<n; i++){
            data[i].first = heights[i];
            data[i].second = names[i];
        }
        sort(data.begin(), data.end(), greater<pair<int, string>>());
        for(int i=0; i<n; i++){
            names[i] = data[i].second;
        }
        return names;
    }
};
