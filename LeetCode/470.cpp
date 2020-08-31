// https://leetcode.com/problems/implement-rand10-using-rand7/

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:    
    int rand10() {
        int r1, r2, r3;
        while(1){
            r1 = rand7(), r2 = rand7();
            // maping (r1, r2) to [1..49] uniformly
            r3 = 7*(r1-1)+r2;
            // [1..49] -> [0..48]
            r3--; 
            if(r3 < 40) return (r3%10)+1;
        }
    }
};