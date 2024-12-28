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
    int dfs(TreeNode* r, int depth){
        if(!r)
            return depth;
        return max(dfs(r->left, depth+1), dfs(r->right, depth+1));
    }
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return dfs(root, 0);
    }
};