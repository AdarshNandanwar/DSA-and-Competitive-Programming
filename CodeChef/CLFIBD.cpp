#include<bits/stdc++.h>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int flag=1, i=0;
        string word;
        map<char, int> m;
        map<char, int>::iterator it;
        cin>>word;
        for (int i = 0; i < word.length(); i++){
            m[word[i]]++;
        }
        int size=m.size();
        if(size<3){
            cout<<"Dynamic"<<endl;
            continue;
        }
        int* arr= new int[size];
        for (it=m.begin(); it!=m.end(); it++){
            arr[i]=it->second;
            i++;
        }
        sort(arr, arr+size);
        if(arr[1]+arr[2]!=arr[3]){
            int temp=arr[0];
            arr[0]=arr[1];
            arr[1]=temp;
        }
        for (int i = 2; i < size; i++){
            if((arr[i-1]+arr[i-2])!=arr[i]){
                flag=0;
                break;
            }
        }
        
        if(flag){
            cout<<"Dynamic"<<endl;
        }
        else{
            cout<<"Not"<<endl;;
        }
        delete[] arr;
    }
    return 0;
}