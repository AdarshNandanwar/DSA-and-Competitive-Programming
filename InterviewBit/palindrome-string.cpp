// https://www.interviewbit.com/problems/palindrome-string/

int Solution::isPalindrome(string A) {
    int n = A.length(), p1 = 0, p2 = n-1;
    while(p1<p2){
        while(p1<n and !isalnum(A[p1])) p1++;
        while(p2>=0 and !isalnum(A[p2])) p2--;
        if(p1<p2 and tolower(A[p1]) != tolower(A[p2])) return 0;
        p1++;
        p2--;
    }
    return 1;
}
