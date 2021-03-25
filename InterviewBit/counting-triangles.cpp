// https://www.interviewbit.com/problems/counting-triangles/

// Method 1 (2 Pointers, O(n2)):

#define MOD 1000000007

int Solution::nTriang(vector<int> &A) {
    int n = A.size(), i = 0, left, right, res = 0;
    sort(A.begin(), A.end());
    // i is the 2nd side
    for(int i = 1; i<n-1; i++){
        // left and right are the 1st and 3rd side respectively
        // since 1st and 2nd sides are minimum, l1+l2>l3 is sufficient
        left = i-1, right = n-1;
        while(left>=0 and right>i){
            if(A[left]+A[i] > A[right]){
                res = (res+right-i)%MOD;
                left--;
            } else {
                right--;
            }
        }
    }
    return res;
}

// Method 2 (2 Pointers, Binary Search, O(n*n*logn)):

#define MOD 1000000007

int Solution::nTriang(vector<int> &A) {
    int n = A.size(), i = 0, j = n-1, res = 0;
    sort(A.begin(), A.end());
    for(int i = 1; i<n-1; i++){
        for(int j = 0; j<i; j++){
            res = (res+(upper_bound(A.begin()+i+1, A.end(), A[j]+A[i]-1)-A.begin())-i-1)%MOD;
        }
    }
    return res;
}
