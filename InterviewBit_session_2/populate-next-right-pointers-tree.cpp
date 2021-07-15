// https://www.interviewbit.com/problems/populate-next-right-pointers-tree/

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
        if(!v.size()) break;
        TreeLinkNode * prev = NULL;
        for(auto i:v){
            i->next = prev;
            prev = i;
            if(i->right) q.push(i->right);
            if(i->left) q.push(i->left);
        }
    }
}
