// https://leetcode.com/problems/furthest-building-you-can-reach/

// Method 1 (min heap, O(n)):

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

// Method 2 (Backtracking, will probabily give TLE):

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