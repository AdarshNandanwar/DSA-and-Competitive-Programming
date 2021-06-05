// https://leetcode.com/problems/construct-target-array-with-multiple-sums/

// Method 1 (Optimized Priority Queue):

class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum = 0, n = target.size(), val, decrease, times;
        if(n == 1) return target[0] == 1;
        
        priority_queue<int, vector<int>> pq;
        for(auto &i:target){
            sum += i;
            pq.push(i);
        }
        while(1){
            val = pq.top();                 // sum of array in prev step
            pq.pop();
            if(val == 1) return true;            
            
            decrease = (sum-val);
            times = max(1ll, (val-pq.top())/decrease);

            val -= times*decrease;    // replacing the max value with its prev value in one step
            sum -= times*decrease;
            
            if(val < 1) return false;
            
            pq.push(val);
        }
    }
};

// Method 2 (Priority Queue, TLE):

class Solution {
public:
    bool isPossible(vector<int>& target) {
        int sum = 0, n = target.size(), new_val, max_val;
        priority_queue<int, vector<int>> pq;
        for(auto &i:target){
            sum += i;
            pq.push(i);
        }
        while(1){
            max_val = pq.top();                 // sum of array in prev step
            if(max_val == 1) return 1;
            pq.pop();
            new_val = max_val-(sum-max_val);    // replacing the max value with its prev value
            if(new_val < 1) return false;
            pq.push(new_val);
            sum = max_val; 
        }
    }
};