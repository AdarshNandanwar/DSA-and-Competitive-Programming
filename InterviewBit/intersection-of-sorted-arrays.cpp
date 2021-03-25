// https://www.interviewbit.com/problems/intersection-of-sorted-arrays/

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int na = A.size(), nb = B.size(), p1 = 0, p2 = 0;
    vector<int> res;
    while(p1<na and p2<nb){
        if(A[p1] == B[p2]){
            res.push_back(A[p1]);
            p1++; p2++;
        } else if(A[p1] < B[p2]){
            p1++;
        } else {
            p2++;
        }
    }
    return res;
}
