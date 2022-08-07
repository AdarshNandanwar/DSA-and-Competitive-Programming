// https://leetcode.com/problems/last-stone-weight/

// Method 1 (Max Heap, O(nlogn)):

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto &stone:stones){
            pq.push(stone);
        }
        while(pq.size() > 1){
            int stone1 = pq.top();
            pq.pop();
            int stone2 = pq.top();
            pq.pop();
            int diff = stone1-stone2;
            if(diff){
                pq.push(diff);
            }
        }
        if(pq.empty()){
            return 0;
        } else {
            return pq.top();
        }
    }
};