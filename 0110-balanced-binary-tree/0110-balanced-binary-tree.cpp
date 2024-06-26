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
    int dfs(TreeNode* r){
        if(!r) return 0;
        return max(dfs(r->left), dfs(r->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        int l = dfs(root->left);
        int r = dfs(root->right);
        return abs(r-l) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};