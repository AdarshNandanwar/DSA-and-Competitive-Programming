// Different Names
// Send Feedback
// In Little Flowers Public School, there are many students with same first names. You are given a task to find the students with same names. You will be given a string comprising of all the names of students and you have to tell the name and count of those students having same. If all the names are unique, print -1 instead.
// Note: We don't have to mention names whose frequency is 1.
// Input Format:
// The only line of input will have a string ‘str’ with space separated first names of students.
// Output Format:
// Print the names of students along with their count if they are repeating. If no name is repeating, print -1
// Constraints:
// 1 <= |str| <= 10^5
// Time Limit: 1 second
// Sample Input 1:
// Abhishek harshit Ayush harshit Ayush Iti Deepak Ayush Iti
// Sample Output 1:
// harshit 2
// Ayush 3
// Iti 2
// Sample Input 2:
// Abhishek Harshit Ayush Iti
// Sample Output:
// -1

#include<bits/stdc++.h>
#include<map>
#include<set>
#include<string>
using namespace std;

int main(){
    int count=0, flag=-1;
    string str;
    map<string, int> m;
    set<string> s;
    getline(cin, str);
    for (int i = 0; i <= str.length(); i++){
        if(str[i]==' ' || str[i]=='\0'){
            m[str.substr(i-count,count)]++;
            if(m[str.substr(i-count,count)]==2){
                if(s.find(str.substr(i-count,count))==s.end()){
                    s.insert(str.substr(i-count,count));
                }
                flag=0;
            }
            count=0;
        }else{
            count++;
        }
    }
    set<string>::iterator it;
    for (it=s.begin(); it!=s.end();it++){
        cout<<*it<<" "<<m[*it]<<endl;
    }

    if(flag==-1)
        cout<<flag;
    return 0;
}