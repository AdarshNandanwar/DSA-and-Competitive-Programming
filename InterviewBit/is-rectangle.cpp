// https://www.interviewbit.com/problems/is-rectangle/

// Method 1:

int Solution::solve(int A, int B, int C, int D) {
    vector<int> v = {A, B, C, D};
    sort(v.begin(), v.end());
    return v[0] == v[1] and v[2] == v[3];
}
