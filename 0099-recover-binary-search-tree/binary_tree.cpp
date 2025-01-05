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
    vector<int> v;
    int i = 0;

    void traversal(TreeNode* r){
        if(!r) return;
        traversal(r->left);
        v.push_back(r->val);
        traversal(r->right);
    }

    void recover(TreeNode* r){
        if(!r) return;
        recover(r->left);
        r->val = v[i++];
        recover(r->right);
    }

    void recoverTree(TreeNode* root) {
        if(!root) return;
        traversal(root);
        sort(v.begin(), v.end());
        recover(root);
    }
};