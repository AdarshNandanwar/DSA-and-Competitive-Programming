// https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/

void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int> a(A.begin(), A.end());
    A.clear();
    int p1 = 0, p2 = 0, n = a.size(), m = B.size();
    while(p1<n and p2<m){
        if(a[p1] < B[p2]) A.push_back(a[p1++]);
        else A.push_back(B[p2++]);
    }
    while(p1<n)A.push_back(a[p1++]);
    while(p2<m)A.push_back(B[p2++]);
}
