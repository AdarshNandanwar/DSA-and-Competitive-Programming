// https://www.interviewbit.com/problems/highest-product/

// Method 0 (Greedy, Heap, O(n)):

int Solution::maxp3(vector<int> &A) {    
    priority_queue<int, vector<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int p1 = 1, p2 = 1, maxNum = INT_MIN;
    // lowest 2 number
    for(auto i:A){
        maxHeap.push(i);
        if(maxHeap.size() > 2) maxHeap.pop();
    }
    while(!maxHeap.empty()){
        p1 *= maxHeap.top();
        maxHeap.pop();
    }
    // highest 3 number
    for(auto i:A){
        minHeap.push(i);
        if(minHeap.size() > 3) minHeap.pop();
    }
    while(!minHeap.empty()){
        maxNum = minHeap.top();
        p2 *= minHeap.top();
        minHeap.pop();
    }
    // max([0,1,n-1], [n-3,n-2,n-1]) in sorted A
    return max(p1*maxNum, p2);
}

// Method 1 (Greedy, O(nlogn)):

int Solution::maxp3(vector<int> &A) {
    int n = A.size();
    sort(A.begin(), A.end());
    
    // ANS POS NEG SELECT        
    //  +   3   0  [n-3,n-2,n-1] or [0,1,n-1] (if one of the pos is 0)
    //  -   2   1  [n-3,n-2,n-1] or 0 (if one of the pos is 0)
    //  +   1   2  [n-3,n-2,n-1] or [] (if one of the pos is 0)
    //  -   0   3  [n-3,n-2,n-1]
    
    return max(A[0]*A[1]*A[n-1], A[n-3]*A[n-2]*A[n-1]);
}

// Method 2:

int Solution::maxp3(vector<int> &A) {
    sort(A.begin(), A.end());
    int n = A.size();
    if(n<3) return 0;
    
    int count = 0, prod = 1;
    for(int i = n-1; i>=0; i--){
        if(A[i]){
            prod *= A[i];
            if(++count == 3) break;
        }
    }
    if(count != 3) prod = INT_MIN;
    if(A[1] < 0){
        if(binary_search(A.begin(), A.end(), 0)){
            return max(max(0, A[0]*A[1]*A[n-1]), prod);
        } else {
            return max(A[0]*A[1]*A[n-1], prod);
        }
    } else {
        if(binary_search(A.begin(), A.end(), 0)){
            return max(0, prod);
        } else {
            return prod;
        }
    }
}
