// https://www.interviewbit.com/problems/partitions/

int Solution::solve(int A, vector<int> &B) {
    int sum = 0;
    for(auto i:B) sum += i;
    if(sum%3) return 0;
    sum /= 3;
    int res = 0, freq = 0;
    for(int i = 0; i<B.size()-1; i++){
        if(i > 0) B[i] += B[i-1];
        if(B[i] == 2*sum) res += freq;
        if(B[i] == sum) freq++;
    }
    return res;
}
