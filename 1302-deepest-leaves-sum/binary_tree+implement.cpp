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
    int mxDepth = 0;
    int sum = 0;

    void solve(TreeNode *r, int depth = 0) {
        if (!r) return;
        if (!r->left && !r->right) {
            if (mxDepth < depth) {
                mxDepth = depth;
                sum = r->val;
            } else if (mxDepth == depth) {
                sum += r->val;
            }
        }
        solve(r->left, depth + 1);
        solve(r->right, depth + 1);
    }

    int deepestLeavesSum(TreeNode* root) {
        solve(root);
        return sum;
    }
};