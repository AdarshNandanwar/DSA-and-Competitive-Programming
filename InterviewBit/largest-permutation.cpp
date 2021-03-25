// https://www.interviewbit.com/problems/largest-permutation/

// Method 1 (Greedy, O(nlogn)):

vector<int> Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    vector<int> ind(n);
    for(int i = 0; i<n; i++) ind[A[i]-1] = i;
    vector<int> sA(A.begin(), A.end());
    sort(sA.begin(), sA.end(), greater<int>());
    vector<int> res(n);
    for(int i = 0; i<n and B>0; i++){
        if(sA[i] != A[i]){
            int j = ind[sA[i]-1];
            swap(A[i], A[j]);
            ind[A[i]-1] = i;
            ind[A[j]-1] = j;
            B--;
        }
    }
    return A;
}
