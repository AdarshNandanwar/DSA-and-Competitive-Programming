// Palindromic Substrings
// Send Feedback
// Given a string S, count and return the number of substrings of S that are palindrome.
// Single length substrings are also palindromes. You just need to calculate the count, not the substrings.
// Input Format :
// String S
// Output Format :
// count of palindrome substrings
// Constraints :
// 1 <= Length of S <= 1000
// Sample Input :
// aba
// Sample Output :
// 4
// **Note : Here 4 corresponds to ("a","b","a","aba").

#include<bits/stdc++.h>
using namespace std;

int countPalindromeSubstrings(char s[]) {
	// Write your code here
	int len = 0;
    while(s[len]!='\0'){
        len++;
    }
    int count = 0;
    
    //odd
    for (int i = 0; i < len; i++)
    {
        count++;
        int l, r;
        l = i-1;
        r = i+1;
        while(l>=0 && r<len){
            if(s[l] == s[r]){
                count++;
                l--;
                r++;
            } else {
                break;
            }
        }
    }
    //even
    for (int i = 0; i < len-1; i++)
    {
        if(s[i] == s[i+1]){
            count++;
            int l, r;
            l = i-1;
            r = i+2;
            while(l>=0 && r<len){
                if(s[l] == s[r]){
                    count++;
                    l--;
                    r++;
                } else {
                    break;
                }
            }
        }
    }
    return count;
}

int main(){
    char str[1000];
    cin>>str;
    cout<<countPalindromeSubstrings(str)<<endl;
    return 0;
}