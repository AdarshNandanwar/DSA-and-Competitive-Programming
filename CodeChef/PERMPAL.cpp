#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int odd=0, index=0;
        string str;
        cin>>str;
        int n=str.length();
        map<char, vector<int>> m;
        map<char, vector<int>>::iterator it;
        for (int i = 0; i < n; i++){
            m[str[i]].push_back(i+1);
        }
        int* arr=new int[n];

        for (it=m.begin(); it!=m.end(); it++){
            int j, freq=it->second.size();
            for(j=0; j<(freq-(freq%2)); j++){
                arr[index]=it->second[j++];
                arr[n-1-index]=it->second[j];
                index++;
            }

            if(freq%2==1){
                arr[n/2]=it->second[j];
                odd++;
                if(odd>1)
                    break;
            }  
        }
        if(odd>1){
            cout<<-1<<endl;
        }else{
            for (int i = 0; i < n; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        
        delete[] arr;
    }

    return 0;
}

