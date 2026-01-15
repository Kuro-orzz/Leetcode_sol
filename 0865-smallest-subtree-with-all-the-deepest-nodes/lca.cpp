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
    unordered_map<TreeNode*, int> d;
    unordered_map<TreeNode*, TreeNode*> par;
    int mx_depth = 0;

    void dfs(TreeNode* &r, TreeNode* &p, int depth) {
        if (!r) return;
        d[r] = depth;
        par[r] = p;
        mx_depth = max(mx_depth, depth);
        dfs(r->left, r, depth+1);
        dfs(r->right, r, depth+1);
    }

    TreeNode* solve(){
        vector<TreeNode*> v;
        for (auto &[x,y] : d) {
            if (y == mx_depth) v.push_back(x);
        }
        for (int i = 1; i < v.size(); i++) {
            TreeNode* i1 = v[i-1];
            TreeNode* i2 = v[i];
            while (d[i1] > d[i2]) i1 = par[i1];
            while (d[i2] > d[i1]) i2 = par[i2];
            while (i1 != i2) {
                i1 = par[i1];
                i2 = par[i2];
            }
            v[i] = i2;
        }
        return v.back();
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root, root, 0);
        return solve();
    }
};