// https://leetcode.com/problems/grumpy-bookstore-owner/

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int window_sum = 0, total_satisfied_sum = 0, satisfied_sum = 0, p1 = 0, p2 = 0, n = customers.size(), max_delta = 0;
        
        // [p1, p2)
        for(p2 = 0; p2<X; p2++){
            if(!grumpy[p2]){ 
                satisfied_sum += customers[p2];
                total_satisfied_sum += customers[p2];
            }
            window_sum += customers[p2];
        }
        max_delta = max(max_delta, window_sum-satisfied_sum);
        while(p2<n){
            if(!grumpy[p2]){ 
                satisfied_sum += customers[p2];
                total_satisfied_sum += customers[p2];
            }
            window_sum += customers[p2];
            if(!grumpy[p1]) satisfied_sum -= customers[p1];
            window_sum -= customers[p1];
            
            max_delta = max(max_delta, window_sum-satisfied_sum);
            p1++;
            p2++;
        }
        return total_satisfied_sum+max_delta;
    }
};