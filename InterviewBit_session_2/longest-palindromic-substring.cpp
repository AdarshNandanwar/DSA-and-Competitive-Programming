// https://www.interviewbit.com/problems/longest-palindromic-substring/

// Method 1 (O(n2)):

string Solution::longestPalindrome(string A) {
    int n = A.length(), j;
    string s = "";
    for(int i = 0; i<n; i++){
        j = 0;
        while(i-j>=0 and i+j<n and A[i-j] == A[i+j]){
            if(s.length() < 2*j+1) s = A.substr(i-j, 2*j+1);
            j++;
        }
        j = 0;
        while(i-j>=0 and i+j+1<n and A[i-j] == A[i+j+1]){
            if(s.length() < 2*j+2) s = A.substr(i-j, 2*j+2);
            j++;
        }
    }
    return s;
}
