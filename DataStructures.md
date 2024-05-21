# Data Structures
## Fenwick Tree (Binary Indexed Tree) - One based indexing
```cpp
class FenwickTree{
    vector<int> BIT;

public:
    FenwickTree(int n){
        BIT = vector<int>(n+1, 0);
    }

    void update(int index, int delta){
        index++;
        for(int i=index; i<BIT.size(); i += (i&-i)){
            BIT[i] += delta;
        }
    }

    int prefixSum(int index){
        index++;
        int sum = 0;
        for(int i=index; i>0; i -= (i&-i)){
            sum += BIT[i];
        }
        return sum;
    }
};

FenwickTree* ft;

void initialize(vector<int>& nums) {
    int n = nums.size();
    ft = new FenwickTree(n);
    for(int i=0; i<n; i++){
        ft->update(i, nums[i]);
    }
}

void update(int index, int val) {
    int delta = val-sumRange(index, index);
    ft->update(index, delta);
}

int sumRange(int left, int right) {
    return ft->prefixSum(right) - ft->prefixSum(left-1);
}
```
## AVL Tree
```cpp
struct TreeNode{
    int val;
    int ht;
    TreeNode * left;
    TreeNode * right;

    TreeNode(int val): val(val), ht(1), left(nullptr), right(nullptr) {};
};

int getHeight(TreeNode * root){
    return root == nullptr ? 0 : root->ht;
}

TreeNode * rotateRight(TreeNode * root){
    TreeNode * left = root->left;
    root->left = left->right;
    left->right = root;
    root->ht = 1 + max(getHeight(root->left), getHeight(root->right));
    left->ht = 1 + max(getHeight(left->left), getHeight(left->right));
    return left;
}

TreeNode * rotateLeft(TreeNode * root){
    TreeNode * right = root->right;
    root->right = right->left;
    right->left = root;
    root->ht = 1 + max(getHeight(root->left), getHeight(root->right));
    right->ht = 1 + max(getHeight(right->left), getHeight(right->right));
    return right;
}

int getBalanceFactor(TreeNode * root){
    if(root == nullptr){
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}

TreeNode * insert(TreeNode * root,int val)
{
    if(root == nullptr){
        return new TreeNode(val);
    }

    if(val <= root->val){
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    root->ht = 1 + max(getHeight(root->left), getHeight(root->right));

    int balanceFactor = getBalanceFactor(root);
    if(abs(balanceFactor) > 1){
        // Imbalance
        if(val <= root->val){
            if(val <= root->left->val){
                // LL-imbalance
                root = rotateRight(root);
            } else {
                // LR-imbalance
                root->left = rotateLeft(root->left);
                root = rotateRight(root);
            }
        } else {
            if(val <= root->right->val){
                // RL-imbalance
                root->right = rotateRight(root->right);
                root = rotateLeft(root);
            } else {
                // RR-imbalance
                root = rotateLeft(root);
            }
        }
    }
    return root;  
}
```
## Trie (Prefix Tree)
```cpp
struct TrieNode {
	bool is_word;
	TrieNode * next[128];

	TrieNode(){
		is_word = false;
		for(int i = 0; i<26; i++){
            next[i] = NULL;
        }
	}
};

void insert(TrieNode * root, string s){
	TrieNode * curr = root;
    for(int i = 0; i<s.length(); i++) {
        if(cur->next[s[i]] == NULL){
            cur->next[s[i]] = new TrieNode();
        }
        cur = cur->next[s[i]];
    }
    cur->is_word = true;
}

void search(TrieNode * root, string s){
	TrieNode * curr = root;
    for(int i = 0; i<s.length(); i++){
        if(cur->next[s[i]] == NULL) {
            return false;
        }
        cur = cur->next[s[i]];
    }
    return cur->is_word;
}
```
## BST Iterator
```cpp
class BSTIterator{
    stack<TreeNode *> st;

    BSTIterator(TreeNode * root) {
        pushLeft(root);
    }

    void pushLeft(TreeNode * root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }

    TreeNode * next(){
        TreeNode * cur = st.top();
        st.pop();
        pushLeft(cur->right);
        return cur;
    }

    bool hasNext() {
        return !st.empty();
    }

    TreeNode * peek() {
        return st.top();
    }
};
```
