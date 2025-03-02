// https://leetcode.com/problems/lemonade-change

// Method 1 (Greedy, O(n)):

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // freq = {$5, $10, $20}
        vector<int> freq(3);
        for(int bill:bills){
            if(bill == 5){
                freq[0]++;
            } else if(bill == 10){
                freq[1]++;
                if(freq[0] == 0){
                    return false;
                }
                freq[0]--;
            } else {
                freq[2]++;
                if(freq[1] == 0){
                    if(freq[0] < 3){
                        return false;
                    } else {
                        freq[0] -= 3;
                    }
                } else {
                    freq[1]--;
                    if(freq[0] == 0){
                        return false;
                    } else {
                        freq[0] -= 1;
                    }
                }
            }
        }
        
        return true;
    }
};
