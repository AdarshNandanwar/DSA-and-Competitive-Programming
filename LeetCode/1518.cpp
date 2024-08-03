// https://leetcode.com/problems/water-bottles/

// Method 1 (O(logm(n)) = O(oogn-logm)):

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int numDrink = numBottles;
        while(numBottles >= numExchange){
            int bottlesReceived = numBottles / numExchange;
            int bottlesGiven = bottlesReceived * numExchange;
            numBottles -= bottlesGiven;
            numBottles += bottlesReceived;
            numDrink += bottlesReceived;
        }
        return numDrink;
    }
};
