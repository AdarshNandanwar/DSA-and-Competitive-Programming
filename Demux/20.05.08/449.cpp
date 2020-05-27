// https://leetcode.com/problems/serialize-and-deserialize-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    void constructString(TreeNode * root, string & s){
        if(!root){
            s += "n,";
            return;
        }
        
        // preorder
        s += (to_string(root->val)+',');
        constructString(root->left, s);
        constructString(root->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        constructString(root, s);
        return s;
    }
    
    TreeNode * deconstructString(istringstream & iss){
        string s;
        if(!getline(iss, s, ',')) return NULL;
        if(s == "n") return NULL;
        int num = stoi(s);
        TreeNode * root = new TreeNode(num);
        root->left = deconstructString(iss);
        root->right = deconstructString(iss);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode * root;
        istringstream iss(data);
        return deconstructString(iss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));