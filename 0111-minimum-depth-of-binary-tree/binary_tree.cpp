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
    int ans = INT_MAX;

    void traversal(TreeNode* r, int lv){
        if(!r) return;
        if(!r->left && !r->right){
            ans = min(ans, lv);
            return;
        }
        traversal(r->left, lv+1);
        traversal(r->right, lv+1);
    }

    int minDepth(TreeNode* root) {
        if(!root) return 0;
        traversal(root, 1);
        return ans;      
    }
};