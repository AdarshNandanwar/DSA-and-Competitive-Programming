// https://www.interviewbit.com/problems/3-sum-zero/

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    long n = A.size();
    long p1, p2, target, sum;
    vector<vector<int>> res;
    sort(A.begin(), A.end());
    for(int i = 0; i<n;){
        target = -((long)A[i]);
        p1 = i+1;
        p2 = n-1;
        while(p1<p2){
            sum = (long)A[p1]+A[p2];
            if(sum > target){
                p2--;
            } else if(sum < target){
                p1++;
            } else {
                res.push_back({A[i], A[p1], A[p2]});
                p1++;
                while(p1<p2 and A[p1-1] == A[p1]) p1++;
            }
        }
        i++;
        while(i<n and A[i-1] == A[i]) i++;
    }
    return res;
}
