// https://www.interviewbit.com/problems/find-duplicate-in-array/

// Method 1 (Floyd's slow fast pointer, O(n) time, O(1) space)):

int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    if(n <= 1) return -1;
    
    // since A[i] is in [1,n-1] where n = size of the array
    // 0 will never occur in the array, so let 0 be the starting point
    // lets us a assume a linked list where i -> A[i] -> A[A[i]] -> ...
    // 0 -> A[0] -> A[A[0]] -> ...
    // if cycle is found, 2 nodes will point to the same node which is our ans
    
    int slow = 0, fast = 0;
    do{
        slow = A[slow];
        fast = A[A[fast]];
    } while (slow != fast);
    
    fast = 0;
    while(slow != fast){
        slow = A[slow];
        fast = A[fast];
    }
    return slow;
}

// Method 2 (Bucketing, O(n) time, O(root(n)) space):

int Solution::repeatedNumber(const vector<int> &A) {
    int i, n = A.size(), rt = ceil(sqrt((double)n));
    vector<int> bucket(rt, 0);
    for(i = 0; i<n; i++){
        bucket[(A[i]-1)/rt]++;
        if(bucket[(A[i]-1)/rt] > rt) break;
    }
    // [lb, ub)
    int lb = ((A[i]-1)/rt)*rt, ub = lb+rt;
    vector<bool> found(rt, 0);
    for(auto i:A){
        if(lb<=i-1 and i-1<ub){
            if(found[i-1-lb]) return i;
            found[i-1-lb] = 1;
        }
    }
    // still not found
    found = vector<bool>(n, 0);
    for(auto i:A){
        if(found[i-1]) return i;
        found[i-1] = 1;
    }
    return -1;
}
