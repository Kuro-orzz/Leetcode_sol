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
    vector<pair<int, int>> T;
    int idx = 0;

    void dfs(TreeNode* &r, int lv) {
        if (idx == T.size() || lv != T[idx].first) return;
        r = new TreeNode(T[idx++].second);
        dfs(r->left, lv + 1);
        dfs(r->right, lv + 1);
    }


    TreeNode* recoverFromPreorder(string traversal) {
        int cnt = 0;
        for(int i = 0; i < traversal.size();){
            while(!isdigit(traversal[i]))
                cnt++, i++;
            string num = "";
            while(isdigit(traversal[i]))
                num += traversal[i], i++;
            T.push_back({cnt, stoi(num)});
            cnt = 0;
        }
        TreeNode *ans = NULL;
        dfs(ans, 0);
        return ans;
    }
};