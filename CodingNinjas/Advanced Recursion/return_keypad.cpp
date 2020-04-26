// Return Keypad Code
// Send Feedback
// Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
// Return empty string for numbers 0 and 1.
// Note : The order of strings are not important.
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


#include<bits/stdc++.h>
#include <string>
using namespace std;

int add_letter(int num, string* output, int size){

    //coutld have used a simple array of strings below, as keys of the map are basically the index of the array
    map<int, string> m={{0, ""}, {1, ""}, {2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
    string s= m[num];
    int count=0;
    if(size){
        string* temp = new string[size];
        for (int i = 0; i < size; i++)
        {
            temp[i]=output[i];
        }
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = 0; j < size; j++)
            {
                output[j+(i*size)]=temp[j]+s[i];
                count++;
            }
        }
    }else{
        for (int i = 0; i < s.length(); i++)
        {
            output[i]=s[i];
            count++;
        }
    }
    return count-size;
}

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
   if(num==0){
       return 0;
   }
   int size=keypad(num/10, output);
   int size_inc=add_letter(num%10, output, size);
   return size+size_inc;
}

int main(){
    int n;
    cin>>n;
    string* output=new string[10000];
    int size=keypad(n, output);
    for (int i = 0; i < size; i++)
    {
        cout<<output[i]<<endl;
    }
    delete[] output;
}
