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
    void trav(TreeNode* root){
        if(!root)
            return;
        trav(root->left);
        v.push_back(root->val);
        trav(root->right);
    }
    TreeNode* build(int l, int r){
        if(l > r)
            return NULL;
        int mid = (l+r)>>1;
        TreeNode* rt = new TreeNode(v[mid]);
        rt->left = build(l, mid-1);
        rt->right = build(mid+1, r);
        return rt;
    }
    TreeNode* balanceBST(TreeNode* root) {
        trav(root);
        return build(0, v.size()-1);
    }
};