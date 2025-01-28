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
class BSTIterator {
public:
    vector<int> v;
    int i = -1;

    void inorderTraversal(TreeNode* r){
        if(!r) return;
        inorderTraversal(r->left);
        v.push_back(r->val);
        inorderTraversal(r->right);
    }

    BSTIterator(TreeNode* root) {
        inorderTraversal(root);
    }
    
    int next() {
        return v[++i];
    }
    
    bool hasNext() {
        if(i+1 < v.size()-1) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */