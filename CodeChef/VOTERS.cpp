#include<bits/stdc++.h>
using namespace std;

int main(){
    int n1, n2, n3, id, count=0;
    cin>>n1>>n2>>n3;
    map<int, int> m;
    map<int, int>::iterator it;
    vector<int> ans;

    for (int i = 0; i < n1+n2+n3; i++)
    {
        cin>>id;
        m[id]++;
        if(m[id]==2){
            count++;
            ans.push_back(id);
        }
    }
    cout<<count<<endl;
    sort(ans.begin(), ans.end());
    for(int i=0; i<count; i++){
        cout<<ans[i]<<endl;;
    }
   
    return 0;
}