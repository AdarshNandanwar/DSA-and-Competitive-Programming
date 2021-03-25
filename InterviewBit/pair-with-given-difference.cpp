// https://www.interviewbit.com/problems/pair-with-given-difference/

// Method 1 (Hash Table, O(n) time, O(n) space):

int Solution::solve(vector<int> &A, int B) {
    unordered_set<int> s;
    for(auto i:A){
        if(s.count(i+B) or s.count(i-B)) return 1;
        s.insert(i);
    }
    return 0;
}

// Method 2 (2 Pointer, O(nlogn)):

int Solution::solve(vector<int> &A, int B) {
    int n = A.size(), i = 0, j = 0;
    sort(A.begin(), A.end());
    // A[i]-A[j] == B
    while(i<n and j<n){
        if(i!=j and A[i]-A[j] == B){
            return 1;
        } else if(A[i]-A[j] > B){
            j++;
        } else {
            i++;
        }
    }
    return 0;
}
