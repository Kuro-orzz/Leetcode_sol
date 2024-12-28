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
    vector<int> path;
    void solve(TreeNode* r, int target, int sum = 0){
        if(!r->left && !r->right){
            if(sum+r->val == target){
                ans.push_back(path);
                ans.back().push_back(r->val);
            }
            return;
        }
        path.push_back(r->val);
        if(r->left) solve(r->left, target, sum+r->val);
        if(r->right) solve(r->right, target, sum+r->val);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        solve(root, targetSum);
        return ans;
    }
};