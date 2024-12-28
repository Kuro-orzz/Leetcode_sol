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
    vector<int> bfs(TreeNode* r){
        queue<TreeNode*> q;
        q.push(r);
        vector<int> ans;
        while(!q.empty()){
            int mx = INT_MIN;
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                TreeNode* t = q.front();
                mx = max(mx, t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                q.pop();
            }
            ans.push_back(mx);
        }
        return ans;
    }

    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        return bfs(root);
    }
};