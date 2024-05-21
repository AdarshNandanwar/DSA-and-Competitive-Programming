// https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/

// Method 1 (Hash Table, O(nlogn)):

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> players;
        unordered_set<int> oneLoss, moreThanOneLoss;
        for(const vector<int>& match:matches){
            players.insert(match[0]);
            players.insert(match[1]);
            if(moreThanOneLoss.count(match[1])){
                continue;
            } else if(oneLoss.count(match[1])){
                oneLoss.erase(match[1]);
                moreThanOneLoss.insert(match[1]);
            } else {
                oneLoss.insert(match[1]);
            }
        }
        vector<vector<int>> answer(2, vector<int>(0));
        for(const int player:players){
            if(moreThanOneLoss.count(player)){
                continue;
            } else if(oneLoss.count(player)){
                answer[1].push_back(player);
            } else {
                answer[0].push_back(player);
            }
        }
        return answer;
    }
};