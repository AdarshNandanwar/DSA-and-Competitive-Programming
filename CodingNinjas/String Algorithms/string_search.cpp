// String Search
// Send Feedback
// Given two strings S and T, write a function to find if T is present as a substring inside S or not. If yes, return the starting index otherwise return -1.
// Input format :

// Line 1 : String S

// Line 2 : String T

// Sample Input 1:
// WelcomeBack
// come 
// Sample Output 1:
// 3
// Sample Input 2:
// WelcomeBack
// code
// Sample Output 2:
// -1

#include<bits/stdc++.h>
using namespace std;

// S and T - input strings
// You need to check if string T is present in S or not

int * getLPS(char S[]){
    int len = 0;
    while(S[len] != '\0'){
        len++;
    }
    int * lps = new int[len];
    lps[0] = 0;
    int i = 1, j = 0;
    while(i<len){
        if(S[i] == S[j]){
            lps[i] = j+1;
            i++;
            j++;
        } else {
            if(j == 0){
                lps[i] = 0;
                i++;
            } else {
                j = lps[j-1];
            }
        }
    }
    return lps;
}

int findString(char S[], char T[]) {
    // Write your code here
    int * lps = getLPS(T);
    int i = 0, j = 0;
    int lenS = 0;
    while(S[lenS] != '\0'){
        lenS++;
    }
    int lenT = 0;
    while(T[lenT] != '\0'){
        lenT++;
    }
    while(i<lenS && j<lenT){
        if(S[i] == T[j]){
            i++;
            j++;
        } else {
            if(j!=0){
                j = lps[j-1];
            } else {
                i++;
            }
        }
    }
    if(j == lenT){
        return i-j;
    } else {
        return -1;
    }
}


int main(){
    char S[100];
    char T[100];
    cin>>S>>T;
    cout<<findString(S, T)<<endl;
    
    return 0;
}