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
    int ans = 0;

    int solve(TreeNode* r){
        if(!r)
            return 0;
        int le = solve(r->left);
        int ri = solve(r->right);
        ans += abs(le)+abs(ri);
        return r->val-1 + le + ri;
    }
    int distributeCoins(TreeNode* root) {
        solve(root);
        return ans;
    }
};