// https://www.interviewbit.com/problems/min-stack/

stack<int> st;
vector<int> minEle;

MinStack::MinStack() {
    while(!st.empty()) st.pop();
    minEle.clear();
}

void MinStack::push(int x) {
    if(st.empty()) minEle.push_back(x);
    else minEle.push_back(min(minEle.back(), x));
    st.push(x);
}

void MinStack::pop() {
    if(st.empty()) return;
    st.pop();
    minEle.pop_back();
}

int MinStack::top() {
    return st.empty() ? -1 : st.top();
}

int MinStack::getMin() {
    return st.empty() ? -1 : minEle.back();
}

