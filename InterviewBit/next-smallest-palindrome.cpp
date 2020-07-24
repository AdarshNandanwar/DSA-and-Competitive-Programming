// https://www.interviewbit.com/problems/next-smallest-palindrome/

string Solution::solve(string A) {
    int n = A.size();
    if(n%2){
        // odd
        int mid = n/2, i;
        
        string next = A.substr(0, mid);
        reverse(next.begin(), next.end());
        next = A.substr(0, mid)+string(1, A[mid])+next;
        if(A < next) return next;
        
        for(i = 0; mid-i>=0;i++){
            if(A[mid-i] != '9'){
                next[mid-i] = next[mid+i] = A[mid-i]+1;
                return next;
            } else {
                next[mid-i] = next[mid+i] = '0';
            }
        }
        
        // all nines
        return "1"+string(n-1, '0')+"1";
    } else {
        // even
        int mid = n/2, i;
        
        string next = A.substr(0, mid);
        reverse(next.begin(), next.end());
        next = A.substr(0, mid)+next;
        if(A < next) return next;
        
        for(i = 0; mid+i<n;i++){
            if(A[mid-i-1] != '9'){
                next[mid-i-1] = next[mid+i] = A[mid-i-1]+1;
                return next;
            } else {
                next[mid-i-1] = next[mid+i] = '0';
            }
        }
        
        // all nines
        return "1"+string(n-1, '0')+"1";
    }
}
