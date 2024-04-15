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
    int ans = 0, num = 0;
    int sumNumbers(TreeNode* root) {
        num = num*10+root->val;
        if(root->left)
            sumNumbers(root->left);
        if(root->right)
            sumNumbers(root->right);
        if(!root->left && !root->right)
            ans += num;
        num /= 10;
        return ans;
    }
};