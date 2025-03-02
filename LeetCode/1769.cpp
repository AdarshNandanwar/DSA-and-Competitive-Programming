// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

// Method 1 (Prefix Sum, O(n) time, O(n) space):

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        
        vector<int> operationsLeft(n); // Number of operations required to move all balls to the left [0 .. i) in to index i
        int leftCount = boxes[0] - '0';
        for(int i=1; i<n; i++){
            operationsLeft[i] = operationsLeft[i-1] + leftCount;
            leftCount += boxes[i] - '0';
        }
        vector<int> operationsRight(n); // Number of operations required to move all balls to the right (i .. n-1] in to index i
        int rightCount = boxes[n-1] - '0';
        for(int i=n-2; i>=0; i--){
            operationsRight[i] = operationsRight[i+1] + rightCount;
            rightCount += boxes[i] - '0';
        }

        vector<int> operations(n);
        for(int i=0; i<n; i++){
            operations[i] = operationsLeft[i] + operationsRight[i];
        }

        return operations;
    }
};
