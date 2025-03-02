// https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/

// Method 1 (Hash map, O(n) time, O(n) space):

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int distinct = 0;
        int queryCount = queries.size();
        unordered_map<int, int> ballColors;
        unordered_map<int, int> colorFreq;
        vector<int> res(queryCount);
        for(int i=0; i<queryCount; i++){
            int ball = queries[i][0];
            int color = queries[i][1];

            if(ballColors.count(ball)){
                int prevColor = ballColors[ball];
                colorFreq[prevColor]--;
                if(colorFreq[prevColor] == 0){
                    distinct--;
                }
            }

            ballColors[ball] = color;
            colorFreq[color]++;
            if(colorFreq[color] == 1){
                distinct++;
            }

            res[i] = distinct;
        }

        return res;
    }
};
