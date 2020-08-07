// https://www.interviewbit.com/problems/convert-to-palindrome/

int isPalindrome(string & s, int st, int end){
    while(st<=end) if(s[st++] != s[end--]) return 0;
    return 1;
}
int Solution::solve(string s) {
    int n = s.length();
    int p1 = 0, p2 = n-1;
    while(p1<p2){
        if(s[p1] != s[p2]) return isPalindrome(s, p1+1, p2) or isPalindrome(s, p1, p2-1);
        p1++; 
        p2--;
    }
    // given input is a palindrome
    return 1;
}
