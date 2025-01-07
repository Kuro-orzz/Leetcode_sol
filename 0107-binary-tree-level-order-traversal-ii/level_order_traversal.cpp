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
    vector<vector<int>> ans;

    void bfs(TreeNode* r){
        queue<TreeNode*> q;
        ans.push_back({r->val});
        q.push(r);
        while(!q.empty()){
            vector<TreeNode*> t;
            while(!q.empty()){
                t.push_back(q.front());
                q.pop();
            }
            vector<int> val;
            for(int i = 0; i < t.size(); i++){
                if(t[i]->left){
                    val.push_back(t[i]->left->val);
                    q.push(t[i]->left);
                }
                if(t[i]->right){
                    val.push_back(t[i]->right->val);
                    q.push(t[i]->right);
                }
            }
            ans.push_back(val);
        }
        ans.pop_back();
        reverse(ans.begin(), ans.end());
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return ans;
        bfs(root);
        return ans;
    }
};