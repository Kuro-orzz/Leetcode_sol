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
    int mx_level = 1;
    vector<int> score;

    void dfs(TreeNode* r, int level) {
        if (!r) return;
        score[level] += r->val;
        mx_level = max(mx_level, level);
        dfs(r->left, level + 1);
        dfs(r->right, level + 1);
    }

    int maxLevelSum(TreeNode* root) {
        score.resize(1e4+6, 0);
        dfs(root, 1);
        int ans = 1;
        for (int i = 1; i <= mx_level; i++) {
            if (score[i] > score[ans]) ans = i;
        }
        return ans;
    }
};