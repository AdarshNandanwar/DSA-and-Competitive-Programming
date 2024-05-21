// https://leetcode.com/problems/relative-ranks/

// Method 1 (Hash Map, O(nlogn) time, O(n) space):

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> sortedScore(score);
        sort(sortedScore.begin(), sortedScore.end(), greater<int>());
        unordered_map<int, int> index;
        for(int i=0; i<n; i++){
            index[sortedScore[i]] = i;
        }
        vector<string> ans(n);
        for(int i=0; i<n; i++){
            int rank = index[score[i]] + 1;
            if(rank == 1){
                ans[i] = "Gold Medal";
            } else if(rank == 2){
                ans[i] = "Silver Medal";
            } else if(rank == 3){
                ans[i] = "Bronze Medal";
            } else {
                ans[i] = to_string(rank);
            }
        }
        return ans;
    }
};
