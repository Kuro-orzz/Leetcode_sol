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
    void dfs(TreeNode* l, TreeNode* r, int lv){
        if(!l || !r) return;
        if(lv % 2 == 0){
            int tmp = l->val;
            l->val = r->val;
            r->val = tmp;
        }
        dfs(l->left, r->right, lv+1);
        dfs(l->right, r->left, lv+1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, 0);
        return root;
    }
};