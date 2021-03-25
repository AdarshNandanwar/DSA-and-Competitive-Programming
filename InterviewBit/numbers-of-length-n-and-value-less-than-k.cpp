// https://www.interviewbit.com/problems/numbers-of-length-n-and-value-less-than-k/

void helper(unordered_set<int> &s, int B, int C, int index, int & count, vector<int> & lessNum){
    if(index>=B) return;
    int digit = (C/(long)pow(10, B-index-1))%10;
    if(index == 0 and s.count(0)) count += ((lessNum[digit]-1)*pow(s.size(), B-index-1));
    else count += (lessNum[digit]*pow(s.size(), B-index-1));
    if(s.count(digit)) helper(s, B, C, index+1, count, lessNum);
}

int Solution::solve(vector<int> &A, int B, int C) {
    int n = A.size();
    if(n == 0 or B == 0 or C == 0) return 0;
    if(B == 1) return lower_bound(A.begin(), A.end(), C)-A.begin();
    if(B > to_string(C).length()) return 0;
    if(B < to_string(C).length()) return A[0]==0 ? pow(n, B-1)*(n-1) : pow(n, B);
    
    vector<int> lessNum(10, 0);
    for(int j = 9;j>=0; j--){
        for(auto i:A){
            if(j>i) lessNum[j]++;
            else break;
        }
    }
    unordered_set<int> s(A.begin(), A.end());
    int count = 0;
    helper(s, B, C, 0, count, lessNum);
    return count;
}
