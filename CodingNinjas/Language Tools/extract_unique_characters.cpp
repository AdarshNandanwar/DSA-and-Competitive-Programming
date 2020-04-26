// Extract Unique characters
// Send Feedback
// Given a string, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same.
// Input format :
// String S
// Output format :
// Output String
// Constraints :
// 1 <= Length of S <= 50000
// Sample Input 1 :
// ababacd
// Sample Output 1 :
// abcd
// Sample Input 2 :
// abcde
// Sample Output 2 :
// abcde

#include<bits/stdc++.h>
#include<vector>
#include<set>
#include<string>
#include<cstring>
using namespace std;

char* uniqueChar(char *str){
    char* ans = new char[strlen(str)];
    int count=0;
    set<char> s;
    for (int i = 0; i < strlen(str); i++)
    {
        if(s.find(str[i])==s.end()){
            s.insert(str[i]);
            ans[count]=str[i];
            count++;
        }
    }
    ans[count]='\0';
    return ans;
}