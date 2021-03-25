#include<bits/stdc++.h>
using namespace std;

class minStack{
    stack<int> primaryStack;
    stack<int> lastMinValStack;

    public:

    void push(int val){
        primaryStack.push(val);
        if(lastMinValStack.empty() or val < lastMinValStack.top()){
            lastMinValStack.push(val);
        }
    }

    void pop(){
        if(primaryStack.empty() or lastMinValStack.empty()) return;
        int popVal = primaryStack.top();
        primaryStack.pop();
        if(popVal == lastMinValStack.top()){
            lastMinValStack.pop();
        }
    }

    int top(){
        if(primaryStack.empty()) return -1;
        return primaryStack.top();
    }

    int getMin(){
        if(lastMinValStack.empty()) return -1;
        return lastMinValStack.top();
    }
};