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
    int mod = 1e9 + 7;
    int cnt = 1;
    unordered_map<int, int> dp;

    int dfs(TreeNode* r) {
        if (!r) return 0;
        int t = cnt;
        dp[t] = r->val;
        cnt++; dp[t] += dfs(r->left);
        cnt++; dp[t] += dfs(r->right);
        return dp[t];
    }

    int maxProduct(TreeNode* root) {
        dfs(root);
        long long ans = 0;
        for (auto &it : dp) {
            ans = max(ans, 1ll * it.second * (dp[1] - it.second));
        }
        return ans % mod;
    }
};