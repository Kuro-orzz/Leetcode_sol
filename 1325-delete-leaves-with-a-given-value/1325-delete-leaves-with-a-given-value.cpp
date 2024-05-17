/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) { 
        if(root->left)
            if(root->left->left || root->left->right)
                    removeLeafNodes(root->left, target);
        if(root->right)
            if(root->right->left || root->right->right)
                removeLeafNodes(root->right, target);
        // if(!root->left || !root->right)
        //     return root;
        if(root->left)
            if(root->left->val == target && !root->left->left && !root->left->right)
                root->left = NULL;
        if(root->right)
            if(root->right->val == target && !root->right->left && !root->right->right)
                root->right = NULL;
        if(root->val == target && !root->left && !root->right)
            return NULL;
        return root;
    }
};