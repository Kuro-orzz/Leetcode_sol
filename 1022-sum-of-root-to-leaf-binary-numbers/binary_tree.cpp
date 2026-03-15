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
    int sumLeaf(TreeNode *r, string &cur) {
        if (!r) return 0;
        int sum = 0;
        cur += to_string(r->val);
        if (!r->left && !r->right) {
            sum += bitset<32>(cur).to_ulong();
        } else {
            sum += sumLeaf(r->left, cur) + sumLeaf(r->right, cur);
        }
        cur.pop_back();
        return sum;
    }

    int sumRootToLeaf(TreeNode* root) {
        string s = "";
        return sumLeaf(root, s);
    }
};