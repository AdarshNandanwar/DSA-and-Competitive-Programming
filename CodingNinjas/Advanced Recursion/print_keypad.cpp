// Print Keypad Combinations Code
// Send Feedback
// Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
// Note : The order of strings are not important. Just print different strings in new lines.
// Input Format :
// Integer n
// Output Format :
// All possible strings in different lines
// Constraints :
// 1 <= n <= 10^6
// Sample Input:
// 23
// Sample Output:
// ad
// ae
// af
// bd
// be
// bf
// cd
// ce
// cf


#include <iostream>
#include <string>
using namespace std;

void recurse_combinations(int num, string output){
    if(num==0){
        cout<<output<<endl;
        return;
    }
    string key[10]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string s = key[num%10];
    for (int i = 0; i < s.length(); i++)
    {
        recurse_combinations(num/10, s[i]+output);
    }
    return;
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
   string output="";
    recurse_combinations(num, output);
    return;
}

int main(){
    int n;
    cin>>n;
    printKeypad(n);
    return 0;
}