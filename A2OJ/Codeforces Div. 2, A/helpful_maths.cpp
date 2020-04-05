#include<bits/stdc++.h>
using namespace std;

int main(){
    string sumstr;
    cin>>sumstr;
    int len = sumstr.length();
    int index = 0;
    int * arr = new int[(len/2) + 1];
    for (int i = 0; i < len; i++)
    {
        if(sumstr[i] != '+'){
            arr[index] = (int)sumstr[i] - 48;
            index++;
        }
    }
    sort(arr, arr + (len/2)+1);
    cout<<arr[0];
    for (int i = 1; i < (len/2)+1; i++)
    {
        cout<<'+'<<arr[i];
    }   
    return 0;
}