#include<bits/stdc++.h>
#include<map>
#include<set>
using namespace std;

bool containsConsecutiveNumbers(int input[], int len){
	// Write your code here
    map<int, int> m;
    map<int, int>::iterator it;
    int max_element=INT_MIN, min_element=INT_MAX;
    for (int i = 0; i < len; i++)
    {
        max_element=max(max_element, input[i]);
        min_element=min(min_element, input[i]);
        m[input[i]]++;
        if(max_element-min_element > len-1)
            return false;
    }

    for(it=m.begin(); it!=m.end(); it++){
        if(it->second>1)
            return false;
    }

    if((max_element-min_element) == (len-1))
        return true;
    
    return false;
}

// bool containsConsecutiveNumbers(int input[], int len){
// 	// Write your code here
//     set<int> s;
//     int max_element=INT_MIN, min_element=INT_MAX;
//     for (int i = 0; i < len; i++)
//     {
//         if(s.find(input[i])!=s.end()){
//             return false;
//         }else{
//             s.insert(input[i]);
//         }
//         max_element=max(max_element, input[i]);
//         min_element=min(min_element, input[i]);
//         if(max_element-min_element > len-1)
//             return false;
//     }

//     if((max_element-min_element) == (len-1))
//         return true;
    
//     return false;
// }


int main(){
    int size;
    cin>>size;
    int * arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    
    cout<<(containsConsecutiveNumbers(arr, size));
    delete[] arr;
    return 0;
}