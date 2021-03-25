// https://www.interviewbit.com/problems/disjoint-intervals/

int Solution::solve(vector<vector<int> > &A) {
    sort(A.begin(), A.end());
    int curEnd = 0, res = 0;
    for(auto i:A){
        if(i[0] > curEnd){
            res++;
            curEnd = i[1];
        } else {
            curEnd = min(curEnd, i[1]);
        }
    }
    return res;
}