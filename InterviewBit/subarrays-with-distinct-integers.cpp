// https://www.interviewbit.com/problems/subarrays-with-distinct-integers/

// Method 1 (2 Pointers, O(n)):

int atmostB(vector<int> &A, int B){
    unordered_map<int, int> freq;
    int n = A.size(), p1 = 0, p2 = 0, distinct = 0, res = 0;
    while(p2<n){
        if(freq[A[p2]] == 0) distinct++;
        freq[A[p2++]]++;
        while(distinct > B){
            if(freq[A[p1]] == 1) distinct--;
            freq[A[p1++]]--;
        }
        res += (p2-p1);
    }
    return res;
}

int Solution::solve(vector<int> &A, int B) {
    return atmostB(A, B)-atmostB(A, B-1);
}
