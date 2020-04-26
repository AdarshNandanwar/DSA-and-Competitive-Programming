#include<bits/stdc++.h>
using namespace std;

// int maximum_subarray_product(int* arr, int n){
//     int pprod=1, nprod=1, max_prod=INT_MIN, flag=0;
    
//     for (int i = 0; i < n; i++)
//     {
//         if(arr[i]>0){
//             pprod*=arr[i];
//             if(flag){
//                 nprod*=arr[i];
//             }
//         }else if(arr[i]<0){
//             flag=1;
//             int temp=pprod;
//             pprod=nprod;
//             nprod=temp;

//         }else{
//             max_prod=max(max_prod, pprod);
//             pprod=1;
//             nprod=1;
//         }
//     }
//     max_prod=max(max_prod, pprod);
//     return max_prod;
// }

int maximum_subarray_product(int* arr, int n){

    int prod=1, max_prod=INT_MIN, all_negative=1;
    vector<int> v1;
    vector<int> v2;

    for (int i = 0; i < n; i++)
    {
        if(arr[i]>0){
            all_negative=0;
            prod*=arr[i];
        }
        if(arr[i]<=0 || i==(n-1) ){
            if(arr[i]<0)
                v2.push_back(arr[i]);
            v1.push_back(prod);
            prod=1;
        } 
        if(arr[i]==0 || i==(n-1)){
            int prod_between_zeros=1;


            // for (int k = 0; k < v1.size(); k++)
            // {
            //     cout<<v1[k]<<" ";
            // }
            // cout<<endl;
            // for (int k = 0; k < v2.size(); k++)
            // {
            //     cout<<v2[k]<<" ";
            // }
            // cout<<endl;
            
            
            if(v2.size()%2==0){
                for (int j = 0; j < v1.size(); j++)
                {
                    prod_between_zeros*=v1[j];
                }
                for (int j = 0; j < v2.size(); j++)
                {
                    prod_between_zeros*=v2[j];
                }
            }else{
                int size1=v1.size();
                int size2=v2.size();
                if(v2[0]*v1[0]<v2[size2-1]*v1[size1-1]){
                    v2.erase(v2.end()-1);
                    v1.erase(v1.end()-1);
                }else{
                    v2.erase(v2.begin());
                    v1.erase(v1.begin());
                }
                for (int j = 0; j < v1.size(); j++)
                {
                    prod_between_zeros*=v1[j];
                }
                for (int j = 0; j < v2.size(); j++)
                {
                    prod_between_zeros*=v2[j];
                }
            }


            // for (int k = 0; k < v1.size(); k++)
            // {
            //     cout<<v1[k]<<" ";
            // }
            // cout<<endl;
            // for (int k = 0; k < v2.size(); k++)
            // {
            //     cout<<v2[k]<<" ";
            // }
            // cout<<endl;
            
            
            max_prod=max(max_prod, prod_between_zeros);

            v1.clear();
            v2.clear();
        }
    }
    if(all_negative)){
        // -2 0 -1
    }
    return max_prod;
}

int main(){
    int n;
    cin>>n;
    int* arr= new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    cout<<maximum_subarray_product(arr, n);

    delete[] arr;
    return 0;
}