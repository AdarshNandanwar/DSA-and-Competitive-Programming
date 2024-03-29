// https://leetcode.com/problems/flatten-nested-list-iterator/

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
public:
    stack<NestedInteger> stk;
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = nestedList.size()-1; i>=0; i--) stk.push(nestedList[i]);   
    }
    
    int next() {
        if(!stk.empty()){
            int t = stk.top().getInteger();
            stk.pop();
            return t;
        }
        return 0;
    }
    
    bool hasNext() {
        if(stk.empty()){
            return false;
        } else {
            NestedInteger n = stk.top();
            while(!n.isInteger()){
                stk.pop();
                for(int i = n.getList().size()-1; i>=0; i--){
                    stk.push(n.getList()[i]);
                }
                if(stk.empty()) return false;
                n = stk.top();
            }
            return true;
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */