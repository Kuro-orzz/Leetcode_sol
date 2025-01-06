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

    int calc(TreeNode* r, int &sum){
        if(!r) return 0;
        int le = max(calc(r->left, sum), 0);
        int ri = max(calc(r->right, sum), 0);
        sum = max(sum, le+ri+r->val);
        return r->val + max(le, ri);
    }

    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        calc(root, ans);
        return ans;
    }
};