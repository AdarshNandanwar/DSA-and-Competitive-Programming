// https://www.interviewbit.com/problems/remove-consecutive-characters/

// Method 1 (2 Pointers, O(n) time, O(1) space):

string Solution::solve(string A, int B) {
    int n = A.length(), p1 = 0, p2;
    while(p1<n){
        p2 = p1;
        while(p2+1<n and A[p2] == A[p2+1]) p2++;
        if(p2-p1+1 == B) A.erase(p1, p2-p1+1);
        else p1 = p2+1;
    }
    return A;
}

// Method 2 (2 Pointers, O(n) time, O(n) space):

string Solution::solve(string A, int B) {
    int n = A.length(), p1 = 0, p2;
    string res = "";
    while(p1<n){
        p2 = p1;
        while(p2+1<n and A[p2] == A[p2+1]) p2++;
        if(p2-p1+1 != B) res += A.substr(p1, p2-p1+1);
        p1 = p2+1;
    }
    return res;
}
