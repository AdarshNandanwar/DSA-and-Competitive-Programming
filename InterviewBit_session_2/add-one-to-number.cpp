// https://www.interviewbit.com/problems/add-one-to-number/

vector<int> Solution::plusOne(vector<int> &A) {
    int carry = 0, n = A.size(), zeros = 0;
    if(n == 0) return {1};
    A[n-1]++;
    vector<int> res;
    for(int i = n-1; i>=0; i--){
        A[i] += carry;
        carry = A[i]/10;
        res.push_back(A[i]%10);
        if(A[i] == 0) zeros++;
        else zeros = 0;
    }
    if(carry){
        res.push_back(carry);
    } else {
        while(res.back() == 0) res.pop_back();
    }
    return vector<int>(res.rbegin(), res.rend());
}
