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
    vector<int> ans;

    void traversal(TreeNode* r){
        if(!r) return;
        traversal(r->left);
        traversal(r->right);
        ans.push_back(r->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        traversal(root);
        return ans;
    }
};