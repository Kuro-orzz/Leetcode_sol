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
    vector<string> ans;
    string s = "";
    void dfs(TreeNode* r){
        if(s == "")
            s += to_string(r->val);
        else{
            s += "->";
            s += to_string(r->val);
        }
        if(!r->left && !r->right){
            ans.push_back(s);
            return;
        }
        if(r->left){
            dfs(r->left);
            while(s.back() != '>')
                s.pop_back();
            s.pop_back();
            s.pop_back();
        }
        if(r->right){
            dfs(r->right);
            while(s.back() != '>')
                s.pop_back();
            s.pop_back();
            s.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root);
        return ans;
    }
};