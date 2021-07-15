// https://www.interviewbit.com/problems/next-pointer-binary-tree/

// Method 1 (O(1) space):

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    if(!A) return;
    auto level_head = A;
    while(level_head){
        auto cur = level_head;
        while(cur){
            if(cur->left) cur->left->next = cur->right;
            if(cur->right and cur->next) cur->right->next = cur->next->left;
            cur = cur->next;
        }
        level_head = level_head->left;
    }
}

// Method 2 (level order):

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    queue<TreeLinkNode *> q;
    q.push(A);
    while(1){
        vector<TreeLinkNode *> v;
        while(!q.empty()){
            v.push_back(q.front());
            q.pop();
        }
        if(v.size() == 0) break;
        TreeLinkNode * prev = NULL;
        for(auto i:v){
            i->next = prev;
            prev = i;
            if(i->right) q.push(i->right);
            if(i->left) q.push(i->left);
        }
    }
}
