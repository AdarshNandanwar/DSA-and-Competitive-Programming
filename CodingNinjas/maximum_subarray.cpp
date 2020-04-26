#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<int> maxset(int *a, int size) {
	// Write your code here
    int max_sum=INT_MIN, sum=0, flag = 1,max_count=0, count = 0, start_index=0, end_index=size, ans_start_index=0;
    for(int i=0; i<size; i++){
        if(a[i]>=0){
            count++;
            sum+=a[i];
            max_sum=max(max_sum, sum);
        }else{
            flag = 0;
            if(max_sum<sum){
                end_index=i;
                ans_start_index=start_index;
            }else if(max_sum == sum){
                if(count>max_count){
                    end_index=i;
                    ans_start_index=start_index;
                    max_count=count;
                }
            }
            start_index=i+1;
            sum=0;
            count=0;
        }
    }

    if(flag){
        end_index = size;
    }
    vector<int> v;
    
    for(int i=ans_start_index; i<end_index; i++){
        v.push_back(a[i]);
    }
    
    return v;
}

int main(){
    int n;
    cin>>n;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    vector<int> v;
    v = maxset(a, n);
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    
    delete[] a;
    return 0;
}