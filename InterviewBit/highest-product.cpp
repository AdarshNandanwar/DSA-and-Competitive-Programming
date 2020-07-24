// https://www.interviewbit.com/problems/highest-product/

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
