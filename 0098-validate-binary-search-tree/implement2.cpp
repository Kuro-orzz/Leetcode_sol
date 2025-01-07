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
    bool isBST(TreeNode* r, long long mn, long long mx){
        if(!r) return true;
        if(r->val <= mn || r->val >= mx) 
            return false;
        return isBST(r->left, mn, r->val) && isBST(r->right, r->val, mx);
    }

    bool isValidBST(TreeNode* root) {
        if(!root) return true;  
        return isBST(root, LLONG_MIN, LLONG_MAX);
    }
};