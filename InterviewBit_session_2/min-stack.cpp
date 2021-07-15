// https://www.interviewbit.com/problems/min-stack/

// Method 1 (More efficient):

// v[i] = {x, y} = min value is y for index >= x
vector<vector<int>> v;
stack<int> st;

MinStack::MinStack() {
    v.clear();
    while(!st.empty()) st.pop();
}

void MinStack::push(int x) {
    if(v.empty()){
        v.push_back({0, x});
    } else {
        if(v.back()[1] > x){
            v.push_back({st.size(), x});
        }
    }
    st.push(x);
}

void MinStack::pop() {
    if(st.empty()) return;
    st.pop();
    if(st.size() == v.back()[0]) v.pop_back();
}

int MinStack::top() {
    return st.empty() ? -1: st.top();
}

int MinStack::getMin() {
    return v.empty() ? -1: v.back()[1];
}

// Method 2:

vector<int> v;
stack<int> st;

MinStack::MinStack() {
    v.clear();
    while(!st.empty()) st.pop();
}

void MinStack::push(int x) {
    st.push(x);
    if(v.empty()){
        v.push_back(x);
        return;
    }
    v.push_back(min(v.back(), x));
}

void MinStack::pop() {
    if(st.empty()) return;
    v.pop_back();
    st.pop();
}

int MinStack::top() {
    return st.empty() ? -1: st.top();
}

int MinStack::getMin() {
    return v.empty() ? -1: v.back();
}

