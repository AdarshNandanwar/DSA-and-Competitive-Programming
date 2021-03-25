// https://www.interviewbit.com/problems/flip/

// Method 1 (Kadane's Algorithm, O(n)):

vector<int> Solution::flip(string A) {
    int n = A.size(), cur = 0, maxSum = 0, l = -1, r = -1;
    // Kadane's Algo
    // "001101" -> [1, 1, -1, -1, 1, -1]
    // calculate largest sum subarray
    unordered_map<char, int> m;
    m['0'] = 1;
    m['1'] = -1;
    for(int i = 0; i<n; i++){
        cur += m[A[i]];
        if(cur < 0) cur = 0;
        if(maxSum < cur){
            maxSum = cur;
            r = i;
        }
    }
    // getting l with the lowest index
    cur = 0;
    for(int i = r; i>=0; i--){
        cur += m[A[i]];
        if(cur == maxSum) l = i;
    }
    return maxSum == 0 ? vector<int>{} : vector<int>{l+1, r+1};
}

// Method 2 (Prefix Difference, O(n)):

vector<int> Solution::flip(string A) {
    // minDiff = zeros - ones in [0..i]
    // minIndex = index at which minDiff is minimum
    // maxProfit = max number of (0->1)-(1->0)
    int minDiff = 0 , minIndex = -1, l = -1, r = -1, n = A.size(), curZeros = 0, curOnes = 0, curDiff, maxProfit = 0;
    
    for(int i = 0; i<n; i++){
        if(A[i] == '0') curZeros++;
        else curOnes++;
        curDiff = curZeros-curOnes;
        
        if(maxProfit < curDiff-minDiff){
            maxProfit = curDiff-minDiff;
            l = minIndex+1;
            r = i;
        }
        if(minDiff > curDiff){
            minDiff = curDiff;
            minIndex = i;
        }
    }
    return maxProfit == 0 ? vector<int>{} : vector<int>{l+1, r+1};
}
