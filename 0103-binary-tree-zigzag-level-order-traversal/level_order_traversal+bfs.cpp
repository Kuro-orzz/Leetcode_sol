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
        deque<TreeNode*> q;
        ans.push_back({r->val});
        q.push_front(r);
        int cnt = 0;
        while(!q.empty()){
            vector<TreeNode*> t;
            while(!q.empty()){
                t.push_back(q.back());
                q.pop_back();
            }
            vector<int> val;
            for(int i = 0; i < t.size(); i++){
                if(t[i]->left && cnt % 2 == 1){
                    val.push_back(t[i]->left->val);
                    q.push_back(t[i]->left);
                }
                if(t[i]->right){
                    val.push_back(t[i]->right->val);
                    q.push_back(t[i]->right);
                }
                if(t[i]->left && cnt % 2 == 0){
                    val.push_back(t[i]->left->val);
                    q.push_back(t[i]->left);
                }
            }
            ans.push_back(val);
            cnt++;
        }
        ans.pop_back();
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return ans;
        bfs(root);
        return ans;
    }
};