// https://leetcode.com/problems/grumpy-bookstore-owner/

// Method 1 (Suffix Sum, O(n)):

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int satisfiedWithoutTechnique = 0, satisfiedSuffix = 0, numCustomersSuffix = 0;
        for(int i=0; i<minutes; i++){
            satisfiedSuffix += grumpy[i] ? 0 : customers[i];
            satisfiedWithoutTechnique += grumpy[i] ? 0 : customers[i];
            numCustomersSuffix += customers[i];
        }
        int maxDelta = numCustomersSuffix - satisfiedSuffix;
        for(int i=minutes; i<n; i++){
            satisfiedSuffix += grumpy[i] ? 0 : customers[i];
            satisfiedSuffix -= grumpy[i-minutes] ? 0 : customers[i-minutes];
            satisfiedWithoutTechnique += grumpy[i] ? 0 : customers[i];
            numCustomersSuffix += customers[i];
            numCustomersSuffix -= customers[i-minutes];
            maxDelta = max(maxDelta, numCustomersSuffix - satisfiedSuffix);
        }

        return satisfiedWithoutTechnique + maxDelta;
    }
};
