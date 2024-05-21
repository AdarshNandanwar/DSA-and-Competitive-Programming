#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int val): val(val){
        left = nullptr;
        right = nullptr;
    };
};

unordered_map<TreeNode *, int> heights, sizes;

TreeNode * rotateRight(TreeNode* root){
    TreeNode * left = root->left;
    root->left = left->right;
    left->right = root;
    heights[root] = 1+max(heights[root->left], heights[root->right]);
    heights[left] = 1+max(heights[left->left], heights[left->right]);
    sizes[root] -= (sizes[left->left] + 1);
    sizes[left] = 1 + sizes[left->left] + sizes[left->right];
    return left;
}

TreeNode * rotateLeft(TreeNode* root){
    TreeNode * right = root->right;
    root->right = right->left;
    right->left = root;
    heights[root] = 1+max(heights[root->left], heights[root->right]);
    heights[right] = 1+max(heights[right->left], heights[right->right]);
    sizes[root] -= (sizes[right->right] + 1);
    sizes[right] = 1 + sizes[right->right] + sizes[right->left];
    return right;
}

TreeNode * insert(TreeNode * root, int val){
    if(root == nullptr){
        root = new TreeNode(val);
        heights[root] = 1;
        sizes[root] = 1;
        return root;
    }
    
    if(val < root->val){
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    heights[root] = 1+max(heights[root->left], heights[root->right]);
    sizes[root]++;

    int leftHeight = heights[root->left];
    int rightHeight = heights[root->right];
    if(abs(leftHeight-rightHeight) > 1){
        // Imbalance
        if(val < root->val){
            if(val < root->left->val){
                // LL-imbalance
                root = rotateRight(root);
            } else {
                // LR-imbalance
                root->left = rotateLeft(root->left);
                root = rotateRight(root);
            }
        } else {
            if(val < root->right->val){
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

int countSmaller(TreeNode * root, int val){
    if(root == NULL){
        return 0;
    }
    int count = 0;
    if(val <= root->val){
        count += countSmaller(root->left, val);
    } else {
        count++;
        count += sizes[root->left];
        count += countSmaller(root->right, val);
    }
    return count;
}

vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> counts;
    TreeNode * root = nullptr;
    for(int i=n-1; i>=0; i--){
        counts.push_back(countSmaller(root, nums[i]));
        root = insert(root, nums[i]);
    }
    return vector<int>(counts.rbegin(), counts.rend());
}

int main(){
    vector<int> nums = {-1, -1};
    for(auto i:countSmaller(nums)){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}