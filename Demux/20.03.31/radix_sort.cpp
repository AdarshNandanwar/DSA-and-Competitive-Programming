#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;


void radixSortHelper(vector<int> &ar, int placeValue){
    vector<int> count(10, 0);
    int n = ar.size();
    vector<int> res(n);

    // Count Sort
    for(int j = 0; j < n; j++)
        count[(ar[j] / placeValue) % 10]++;

    // Shift
    for(int i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }

    for(int i = n - 1; i >= 0; i--){
        res[count[(ar[i] / placeValue) % 10] - 1] = ar[i];
        count[(ar[i] / placeValue) % 10]--;
    }
    
    // Copy res to ar
    for(int i = 0; i < n; i++)
        ar[i] = res[i];
}

void radixSort(vector<int> &ar){
    
    // Extract the number of digits of the largest number
    int n = ar.size(),
    i, maxNum = INT_MIN, count = 0;

    for (i = 0; i < n; i++){
        maxNum = max(ar[i], maxNum);
    }
    for (i = maxNum; i > 0; i /= 10){
        count++;
    }
    
    int placeValue = 1;
    for(i = 1; i <= count; i++){
        radixSortHelper(ar, placeValue);
        placeValue *= 10;
    }
}


 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v = {1, 5, 2, 5, 8, 2, 3, 6};
    radixSort(v);

    for(auto i:v){
        cout<<i<<" ";
    }cout<<endl;
    
    return 0;
}
