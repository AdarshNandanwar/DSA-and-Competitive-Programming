// https://www.interviewbit.com/problems/2sum-binary-tree/

// Method 1 (O(n), time, O(log(n)) space):

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class BSTIterator{
    public:
    stack<TreeNode *> st;
    BSTIterator(TreeNode *root) {
        pushLeft(root);
    }
    void pushLeft(TreeNode * root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
    /** @return the next smallest number */
    int next() {
        auto top = st.top();
        st.pop();
        pushLeft(top->right);
        return top->val;
    }
    int peek() {
        return st.top()->val;
    }
};
class BSTReverseIterator{
    public:
    stack<TreeNode *> st;
    BSTReverseIterator(TreeNode *root) {
        pushRight(root);
    }
    void pushRight(TreeNode * root){
        while(root){
            st.push(root);
            root = root->right;
        }
    }
    bool hasPrev() {
        return !st.empty();
    }
    int prev() {
        auto top = st.top();
        st.pop();
        pushRight(top->left);
        return top->val;
    }
    int peek() {
        return st.top()->val;
    }
};
 
int Solution::t2Sum(TreeNode* A, int B) {
    BSTIterator it1(A);
    BSTReverseIterator it2(A);
    
    while(it1.hasNext() and it2.hasPrev() and it1.peek() < it2.peek()){
        if(it1.peek()+it2.peek() < B){
            it1.next();
        } else if(it1.peek()+it2.peek() > B){
            it2.prev();
        } else {
            return 1;
        }
    }
    return 0;
}

// Method 2 (O(n), time, O(n) space):

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
  
bool helper(TreeNode* A, int & B, unordered_set<int> & s) {
    if(!A) return 0;
    if(helper(A->left, B, s)) return 1;
    if(A->val >= B) return 0;
    if(s.count(B-A->val)) return 1;
    s.insert(A->val);
    return helper(A->right, B, s);
}
 
int Solution::t2Sum(TreeNode* A, int B) {
    unordered_set<int> s;
    return helper(A, B, s);
}
