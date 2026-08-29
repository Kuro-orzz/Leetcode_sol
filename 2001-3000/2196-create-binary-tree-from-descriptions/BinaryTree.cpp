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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        unordered_map<int, pii> mp1;
        unordered_map<int, int> mp2;
        for (int i = 0; i < n; i++) {
            int par = descriptions[i][0];
            int child = descriptions[i][1];
            int isLeft = descriptions[i][2];
            if (isLeft) mp1[par].fi = child;
            else mp1[par].se = child;
            mp2[child] = par;
        }
        int root = descriptions[0][0];
        while (mp2.count(root)) {
            root = mp2[root];
        }
        TreeNode *ans = new TreeNode(root);
        queue<TreeNode*> q;
        q.push(ans);
        while (!q.empty()) {
            TreeNode* u = q.front(); q.pop();
            if (!mp1.count(u->val)) continue;
            if (mp1[u->val].fi) {
                u->left = new TreeNode(mp1[u->val].fi);
                q.push(u->left);
            }
            if (mp1[u->val].se) {
                u->right = new TreeNode(mp1[u->val].se);
                q.push(u->right);
            }
        }
        return ans;
    }
};