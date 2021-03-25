#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[1000];
ll heap_size = 0;

void heapify_up(ll i){
    if(i == 1){
        return;
    }
    ll parent = i/2;
    if(arr[parent] < arr[i]){
        swap(arr[parent], arr[i]);
        heapify_up(parent);
    } 
}

void insert(ll x){
    heap_size++;
    arr[heap_size] = x;
    heapify_up(heap_size);
}

int get_max(){
    if(heap_size == 0){
        return -1;
    }
    return arr[1];
}

void heapify_down(ll i){
    ll left = 2*i;
    ll right = 2*i+1;

    ll mx = i;
    if(left <= heap_size && arr[left]>arr[mx]){
        mx = left;
    }
    if(right <= heap_size && arr[right]>arr[mx]){
        mx = right;
    }
    if(mx != i){
        swap(arr[mx], arr[i]);
        heapify_down(mx);
    }
    return;
}

void remove_max(){
    if(heap_size == 0){
        return;
    }
    arr[1] = arr[heap_size];
    heap_size--;
    heapify_down(1);
}

void heapify_array(ll * arr, ll n){
    
}

int main(){
    ll n;
    cin>>n;
    for (ll i = 0; i < n; i++)
    {
        ll data;
        cin>>data;
        insert(data);
    }
    while(heap_size){
        cout<<get_max()<<" ";
        remove_max();
    }cout<<endl;

    return 0;
}