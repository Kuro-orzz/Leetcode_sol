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
class FindElements {
public:
    unordered_set<int> s;

    FindElements(TreeNode* root) {
        root->val = 0;
        s.insert(0);
        traversal(root);
    }
    
    bool find(int target) {
        return s.count(target);
    }

    void traversal(TreeNode* r){
        if(r->left != NULL){
            int val = 2 * r->val + 1;
            s.insert(val);
            r->left->val = val;
            traversal(r->left);
        }
        if(r->right != NULL){
            int val = 2 * r->val + 2;
            s.insert(val);
            r->right->val = val;
            traversal(r->right);
        }
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */