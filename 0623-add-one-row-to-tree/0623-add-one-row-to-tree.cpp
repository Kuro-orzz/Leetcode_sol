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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        if(depth == 2){
            if(root->left){
                TreeNode* newNodeL = new TreeNode(val);
                newNodeL->left = root->left;
                root->left = newNodeL;
            }
            else{
                TreeNode* newNodeL = new TreeNode(val);
                root->left = newNodeL;
            }
            if(root->right){
                TreeNode* newNodeR = new TreeNode(val);
                newNodeR->right = root->right;
                root->right = newNodeR;
            }
            else{
                TreeNode* newNodeR = new TreeNode(val);
                root->right = newNodeR;
            }
            return root;
        }
        if(root->left)
            addOneRow(root->left, val, depth-1);
        if(root->right)
            addOneRow(root->right, val, depth-1);

        return root;
    }
};