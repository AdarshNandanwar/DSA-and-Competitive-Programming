// https://leetcode.com/problems/maximal-score-after-applying-k-operations/

// Method 1 (Max Heap, O((n+k)logn)):

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> pq;
        for(int num:nums){
            pq.push(num);
        }
        long long res = 0;
        while(k--){
            int maxElement = pq.top();
            pq.pop();
            res += maxElement;
            int carry = (maxElement % 3) > 0;
            maxElement /= 3;
            maxElement += carry;
            pq.push(maxElement);
        }
        return res;
    }
};
