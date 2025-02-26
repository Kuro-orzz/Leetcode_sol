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
    TreeNode* recoverFromPreorder(string traversal) {
        vector<pair<int, int>> T;
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
        TreeNode *ans = new TreeNode(T[0].second);
        bool check = false;
        for(int i = 1; i < T.size(); i++){
            TreeNode* cur = ans;
            for(int j = 0; j < T[i].first-1; j++)
                if(cur->right)
                    cur = cur->right;
                else
                    cur = cur->left;
            TreeNode* newNode = new TreeNode(T[i].second);
            if(cur->left)
                cur->right = newNode;
            else
                cur->left = newNode;
        }
        return ans;
    }
};