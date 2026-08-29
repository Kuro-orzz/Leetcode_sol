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
    int ans = INT_MIN;

    int calc(TreeNode* r, int sum = 0){
        if(!r) return sum;
        int le = max(calc(r->left), 0);
        int ri = max(calc(r->right), 0);
        int t = max(le+r->val, ri+r->val);
        ans = max({ans, t, r->val, le+ri+r->val});
        return t;
    }

    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        calc(root);
        return ans;
    }
};