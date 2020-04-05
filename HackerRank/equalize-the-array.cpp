#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    map<int, int> m;
    int max_element = -1, max_element_count = -1;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin>>temp;
        m[temp]++;
        if(m[temp] > max_element_count){
            max_element = temp;
            max_element_count = m[temp];
        }
    }
    cout<<n-m[max_element]<<endl;
    return 0;
}