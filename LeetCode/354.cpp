// https://leetcode.com/problems/russian-doll-envelopes/

// Method 1 (Sorting, Binary Search, O(nlogn)):

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> & a, const vector<int> & b){
            return a[0]==b[0] ? a[1]>b[1] : a[0]<b[0];
        });
        // Longest Increasing Subsequence
        vector<int> lis;
        for(auto &envelope:envelopes){
            int height = envelope[1];
            auto itr = lower_bound(lis.begin(), lis.end(), height);
            if(itr == lis.end()){
                lis.push_back(height);
            } else {
                *itr = height;
            }
        }
        return lis.size();
    }
};

// Alternate Code

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> & a, const vector<int> & b){
            return a[0]==b[0] ? a[1]>b[1] : a[0]<b[0];
        });
        // Longest Increasing Subsequence
        set<int> lis;
        for(auto &envelope:envelopes){
            int height = envelope[1];
            auto itr = lis.lower_bound(height);
            if(itr != lis.end()){
                lis.erase(*itr);
            }
            lis.insert(height);
        }
        return lis.size();
    }
};