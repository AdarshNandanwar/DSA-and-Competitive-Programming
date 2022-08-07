// https://leetcode.com/problems/poor-pigs/

// Method 1 (Math, Permutations, O(buckets/iterationsLefts)):

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        
        // In one iteration:                
            // 1 pig => narrow down to atmost ceil(n/2) eleminations
            // 2 pigs => narrow down to atmost ceil(n/4) eleminations
            // 3 pigs => narrow down to atmost ceil(n/8) eleminations
            // x pigs => narrow down to atmost ceil(n/(2^x)) eleminations

            // Hence, for 1000 buckets, we need at max ceil(log2(1000) = 10 pigs
        
        // If we can have >1 iterations:
            // See https://leetcode.com/problems/poor-pigs/discuss/94266/Another-explanation-and-solution
            // buckets <= (1+iterations)^pigs
        
        int iterationsLeft = minutesToTest/minutesToDie;
        int pigs = 0;
        int bucketsCoveredByCurrentPigs = 1;
        while(buckets > bucketsCoveredByCurrentPigs){
            bucketsCoveredByCurrentPigs *= (1+iterationsLeft);
            pigs++;
        }        
        return pigs;        
    }
};