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
#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    int ans = 0;

    pii solve(TreeNode *r, int sum = 0, int cnt = 0) {
        if (!r) return {0, 0};
        pii left = solve(r->left);
        pii right = solve(r->right);
        sum = r->val + left.fi + right.fi;
        cnt = 1 + left.se + right.se;
        if (r->val == sum / cnt) ans++;
        return {sum, cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};