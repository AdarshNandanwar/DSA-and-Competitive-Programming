// Love for Characters
// Send Feedback
// Ayush loves the characters ‘a’, ‘s’, and ‘p’. He got a string of lowercase letters and he wants to find out how many times characters ‘a’, ‘s’, and ‘p’ occurs in the string respectively. Help him find it out.
// Input:
// First line contains an integer denoting length of the string.
// Next line contains the string.
// Constraints:
// 1<=n<=10^5
// ‘a’<= each character of string <= ‘z’
// Output:
// Three space separated integers denoting the occurrence of letters ‘a’, ‘s’ and ‘p’ respectively.
// Sample Input:
// 6
// aabsas
// Sample output:
// 3 2 0

#include<bits/stdc++.h>
#include<unordered_map>
#include<string>
using namespace std;

int main(void){
    int n;
    cin>>n;
    string str;
    cin>>str;

    unordered_map<char,int> m;
    for (int i = 0; i < n; i++)
    {
        m[str[i]]++;
    }
    cout<<m['a']<<" "<<m['s']<<" "<<m['p'];
    return 0;
}