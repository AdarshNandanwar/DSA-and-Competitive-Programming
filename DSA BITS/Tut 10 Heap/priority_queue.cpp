#include<bits/stdc++.h>
using namespace std;

struct compare{
    bool operator()(int a, int b){
        // This is opposite of sort, '<' will give descending order
        return a<b;
    }
};

int main(){
    //MAX HEAP
    priority_queue<int> pq_max;
    
    //MIN HEAP
    priority_queue<int, vector<int>, greater<int>> pq_min;

    //CUSTOM COMPARATOR
    priority_queue<int, vector<int>, compare> pq_custom;
    
    pq_max.push(5);
    pq_max.push(2);
    pq_max.push(3);
    pq_max.push(4);
    while(!pq_max.empty()){
        cout<<pq_max.top()<<" ";
        pq_max.pop();
    }


}