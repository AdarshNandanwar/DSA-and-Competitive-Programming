// https://www.interviewbit.com/problems/palindrome-integer/

// Method 1 (O(n) time, O(1) space):

int Solution::isPalindrome(int A) {
    if(A<0) return 0;
    int n = 0, a = A;
    while(a){
        n++;
        a/=10;
    }
    for(int i = 0, j = n-1; i<j; i++, j--){
        if((int)(A/pow(10, i))%10 != (int)(A/pow(10, j))%10) return 0;
    }
    return 1;
}

// Method 2 (String, O(n) time, O(32) space):

int Solution::isPalindrome(int A) {
    if(A<0) return 0;
    string s = to_string(A);
    for(int i = 0, j = s.length()-1; i<j; i++, j--) if(s[i] != s[j]) return 0;
    return 1;
}