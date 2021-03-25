// https://www.interviewbit.com/problems/smallest-sequence-with-given-primes/

// Method 1 (3 Pointers, O(n)):

vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> res(1, 1);
    int pa = 0, pb = 0, pc = 0;
    while(res.size() <= D){
        int minNext = min(res[pa]*A, min(res[pb]*B, res[pc]*C));
        if(res.back() != minNext) res.push_back(minNext);
        if(minNext == res[pa]*A){
            pa++;
        } else if(minNext == res[pb]*B){
            pb++;
        } else if(minNext == res[pc]*C){
            pc++;
        }
    }
    res.erase(res.begin());
    return res;
}

// Method 2 (Set, Uses extra memory):

vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> res;
    set<int> s;
    s.insert(A);
    s.insert(B);
    s.insert(C);
    for(int i = 0; i<D; i++){
        int cur = *s.begin();
        res.push_back(cur);
        s.erase(cur);
        s.insert(cur*A);
        s.insert(cur*B);
        s.insert(cur*C);
    }
    return res;
}
