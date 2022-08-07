// https://leetcode.com/problems/flatten-nested-list-iterator/

// Method 1 (Stack, O(1)):

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    stack<NestedInteger> st;
    
    void arrangeStack(){
        while(!st.empty()){
            auto cur = st.top();
            if(cur.isInteger()){
                break;
            }
            st.pop();
            auto childList = cur.getList();
            int sz = childList.size();
            for(int i=sz-1; i>=0; i--){
                st.push(childList[i]);
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        int sz = nestedList.size();
        for(int i=sz-1; i>=0; i--){
            st.push(nestedList[i]);
        }
    }
    
    int next() {
        int res = st.top().getInteger();
        st.pop();
        return res;
    }
    
    bool hasNext() {
        arrangeStack();
        return !st.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

// Method 2 (Hack, O(n) initialization, O(1) average):

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    vector<int> flattened;
    int index;
    
    void flatten(vector<NestedInteger> &nestedList){
        int sz = nestedList.size();
        for(int i=0; i<sz; i++){
            if(nestedList[i].isInteger()){
                flattened.push_back(nestedList[i].getInteger());
            } else {
                flatten(nestedList[i].getList());
            }
        }
    }
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flattened.clear();
        flatten(nestedList);
        index = 0;
    }
    
    int next() {
        index++;
        return flattened[index-1];
    }
    
    bool hasNext() {
        return index < flattened.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */