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
    vector<string> v;
    string s = "";
    void traversal(TreeNode* r){
        s += (char)(r->val+'a');
        if(r->left)
            traversal(r->left);
        if(r->right)
            traversal(r->right);
        if(!r->left && !r->right)
            v.push_back(s);
        s.pop_back();
    }

    string smallestFromLeaf(TreeNode* root) {
        traversal(root);
        for(string &x : v)
            reverse(x.begin(), x.end());
        sort(v.begin(), v.end());
        return v[0];
    }
};