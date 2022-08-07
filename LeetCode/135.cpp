// https://leetcode.com/problems/candy/

// Method 1 (O(n) time, O(1) space):

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int consecutiveUps = 0, consecutiveDowns = 0, lastConsecutiveUps = 0;
        int candiesNeeded = 1;
        for(int i=1; i<n; i++){
            if(ratings[i] > ratings[i-1]){
                consecutiveUps++;
                consecutiveDowns = 0;
                lastConsecutiveUps = consecutiveUps;
                candiesNeeded += (1+consecutiveUps);
            } else if(ratings[i] < ratings[i-1]){
                consecutiveUps = 0;
                consecutiveDowns++;
                if(consecutiveDowns > lastConsecutiveUps){
                    candiesNeeded += (consecutiveDowns+1);  // 1 candy for the peak
                } else {
                    candiesNeeded += (consecutiveDowns);    // add candies for all children in down hill
                }
            } else {
                consecutiveUps = 0;
                consecutiveDowns = 0;
                lastConsecutiveUps = 0;
                candiesNeeded++;                
            }
        }
        return candiesNeeded;
    }
};

// Method 2 (Greedy, O(n) time, O(n) space):

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), res = 0;
        vector<int> distLeft(n, 1), distRight(n, 1);
        for(int i = 1; i<n; i++){
            if(ratings[i]>ratings[i-1]) distLeft[i] = distLeft[i-1]+1;
            else distLeft[i] = 1;
        }
        for(int i = n-2; i>=0; i--){
            if(ratings[i]>ratings[i+1]) distRight[i] = distRight[i+1]+1;
            else distRight[i] = 1;
        }
        for(int i = 0; i<n; i++) res += max(distLeft[i], distRight[i]);
        return res;
    }
};