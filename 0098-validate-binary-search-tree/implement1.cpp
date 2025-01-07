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
    bool isBST(TreeNode* r){
        if(!r) return true;
        if(r->left && r->val <= r->left->val)
            return false;
        if(r->right && r->val >= r->right->val)
            return false;
        return isBST(r->left) && isBST(r->right);
    }

    long long maxLeft(TreeNode* r){
        if(!r) return LLONG_MIN;
        return max({1ll*r->val, maxLeft(r->left), maxLeft(r->right)});
    }

    long long minRight(TreeNode* r){
        if(!r) return LLONG_MAX;
        return min({1ll*r->val, minRight(r->left), minRight(r->right)});
    }

    bool isValidBST(TreeNode* root) {
        if(!root) return true;  
        return isBST(root) && isValidBST(root->left) && isValidBST(root->right)
                && maxLeft(root->left) < root->val && minRight(root->right) > root->val;
    }
};