#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string str;
    cin>>str;
    for (ll i = 0; i < str.length(); i++)
    {
        if(str[i] == ' '){
            str = str.substr(0,i)+str.substr(i+1);
        }
    }
    ll i, len = str.length(), row, col;
    row = sqrt(len);
    if(row*row == len){
        col = row;
    } else {
        col = row+1;
    }
    if(row*col < len) row = col;
    string * arr = new string[row];
    for (ll i = 0; i < row-1; i++)
    {
        arr[i] = str.substr(0, col);
        str = str.substr(col);
    }
    arr[row-1] = str;
    // cout<<str<<endl;
    // for (ll i = 0; i < row; i++)
    // {
    //     for (ll j = 0; j < col; j++)
    //     {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    

    for (ll i = 0; i < col; i++)
    {
        for (ll j = 0; j < row; j++)
        {
            if(i < arr[j].length()) cout<<arr[j][i];
        }
        cout<<' ';
    }
    

    delete [] arr;
    return 0;
}