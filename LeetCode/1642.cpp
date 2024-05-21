// https://leetcode.com/problems/furthest-building-you-can-reach/

// Method 1 (Min heap, O(nlogn)):

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        long curSum = 0;
        long topIncreasesSum = 0;
        int furthest = 0;
        priority_queue<int, vector<int>, greater<int>> topIncreases;
        for(int i=1; i<n; i++){
            int increase = heights[i] - heights[i-1];
            if(increase > 0){
                curSum += increase;
                topIncreasesSum += increase;
                topIncreases.push(increase);
            }
            if(topIncreases.size() > ladders){
                topIncreasesSum -= topIncreases.top();
                topIncreases.pop();
            }
            if(curSum - topIncreasesSum <= bricks){
                furthest = i;
            }
        }
        return furthest;
    }
};

// Alternate Code:

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size(), i;
        // pq contains all the heights climbed by ladders
        priority_queue<int, vector<int>, greater<int>> pq;
        for(i = 1; i<n; i++){
            if(heights[i-1] < heights[i]){
                pq.push(heights[i]-heights[i-1]);
                if(pq.size() > ladders){
                    int bricks_required = pq.top();
                    pq.pop();
                    if(bricks < bricks_required) break;
                    bricks -= bricks_required;
                }
            }
        }
        return i-1;
    }
};

// Method 2 (Max Heap, O(nlogn)):

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>> bricksUsed;
        int n = heights.size(), i;
        for(i=0; i<n-1; i++){
            if(heights[i] >= heights[i+1]){
                continue;
            }
            int diff = heights[i+1] - heights[i];
            if(diff>bricks and ladders>0 and !bricksUsed.empty() and diff<bricksUsed.top()){
                // diff<bricksUsed.top() is corner case where it is better to use ladder now
                // as compared to someplace earlier
                bricks += bricksUsed.top();
                bricksUsed.pop();
                ladders--;
            }
            // We pop only when the top() > diff, so no need for while loop above
            if(diff <= bricks){
                bricksUsed.push(diff);
                bricks -= diff;
            } else if(ladders>0){
                ladders--;
            } else {
                break;
            }
        }
        return i;
    }
};

// Method 3 (Backtracking, will probabily give TLE):

class Solution {
public:
    int helper(vector<int>& heights, int index, int bricks, int ladders){
        int n = heights.size();
        if(bricks<0 or ladders<0) return 0;
        if(index == n-1) return 1;
        int res;
        if(heights[index] < heights[index+1]){
            res = 1+max(helper(heights, index+1, bricks-(heights[index+1]-heights[index]), ladders), helper(heights, index+1, bricks, ladders-1));
        } else {
            res = 1+helper(heights, index+1, bricks, ladders);
        }
        return res;
    }
    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        return helper(heights, 0, bricks, ladders)-1;
    }
};