// https://www.interviewbit.com/problems/gas-station/

// Method 1 (Greedy, O(n)):

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), index;
        vector<int> diff(n);
        for(int i = 0; i<n; i++) diff[i] = gas[i]-cost[i];
        if(accumulate(diff.begin(), diff.end(), 0) < 0) return -1;
        vector<int> prefixDiff(diff);
        for(int i = 1; i<n; i++) prefixDiff[i] += prefixDiff[i-1];
        
        // if question wanted first possible index then:
        
        // bool allPos = true;
        // for(int i = 0; i<n; i++) if(prefixDiff[i] < 0) allPos = false;
        // if(allPos) return 0;
        
        index = min_element(prefixDiff.begin(), prefixDiff.end())-prefixDiff.begin();
        return (index+1)%n;
    }
};

// Method 2 (Greedy, O(n2)):

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    
    int n = A.size(), j;
    vector<int> cost(n);
    
    for(int i = 0; i<n; i++) cost[i] = A[i]-B[i];
    
    for(int i = 0; i<n; i++){
        int N = n, prefix = 0;
        for(j = 0; j<n; j++){
            prefix += cost[(i+j)%n];
            if(prefix < 0) break;
        }
        if(j == n) return i;
    }
    return -1;
}