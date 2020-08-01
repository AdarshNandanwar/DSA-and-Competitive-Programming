// https://www.interviewbit.com/problems/majority-element/

// Method 1 (Boyer–Moore majority vote algorithm, O(n) time, O(1) space):

int Solution::majorityElement(const vector<int> &A) {
    
    // Boyer–Moore majority vote algorithm
    
    int n = A.size();
    if(n == 1) return A[0];
    int num = A[0], count = 1;
    for(int i = 1; i<n; i++){
        if(A[i] == num) count++;
        else count--;
        if(count == 0){
            num = A[i];
            count++;
        }
    }
    count = 0;
    for(auto i:A) count += (i == num);
    return count > n/2 ? num : -1;
}

// Method 2 (Hash Table, O(n) time, O(n) space):

int Solution::majorityElement(const vector<int> &A) {
    int n = A.size();
    unordered_map<int, int> m;
    for(auto i:A){
        m[i]++;
        if(m[i] > n/2) return i;
    }
    return -1;
}