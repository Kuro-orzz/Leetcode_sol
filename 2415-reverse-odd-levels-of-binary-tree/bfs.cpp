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
    TreeNode* bfs(TreeNode* root){
        vector<int> val = {0, root->val};
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* u = q.front(); q.pop();
            if(!u->left || !u->right) continue;
            val.push_back(u->left->val);
            val.push_back(u->right->val);
            q.push(u->left);
            q.push(u->right);
        }
        for(int i = 1; i < __lg(val.size()); i+=2)
            reverse(val.begin()+(1<<i), val.begin()+(1<<(i+1)));

        q.push(root);
        int cnt = 1;
        while(!q.empty()){
            TreeNode* u = q.front(); q.pop();
            if(!u->left || !u->right) continue;
            u->left->val = val[cnt+1];
            u->right->val = val[cnt+2];
            q.push(u->left);
            q.push(u->right);
            cnt += 2;
        }
        return root;
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        return bfs(root);
    }
};