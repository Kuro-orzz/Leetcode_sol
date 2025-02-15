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
    int cntSort(vector<int>& val){
        int op = 0;
        unordered_map<int, int> mp;
        vector<int> tmp = val;
        sort(tmp.begin(), tmp.end());
        for(int i = 0; i < tmp.size(); i++)
            mp[val[i]] = i;
        for(int i = 0; i < val.size(); i++){
            if(val[i] == tmp[i]) continue;
            int p1 = i;
            int p2 = mp[tmp[i]];
            mp[val[p1]] = p2;
            mp[val[p2]] = p1;
            swap(val[p1], val[p2]);
            op++;
        }
        return op;
    }

    int bfs(TreeNode* r){
        int op = 0;
        queue<TreeNode*> q;
        q.push(r);
        while(!q.empty()){
            vector<TreeNode*> t;
            while(!q.empty()){
                t.push_back(q.front());
                q.pop();
            }
            vector<int> val;
            for(int i = 0; i < t.size(); i++){
                if(t[i]->left){
                    val.push_back(t[i]->left->val);
                    q.push(t[i]->left);
                }
                if(t[i]->right){
                    val.push_back(t[i]->right->val);
                    q.push(t[i]->right);
                }
            }
            op += cntSort(val);
        }
        return op;
    }

    int minimumOperations(TreeNode* root) {
        return bfs(root);
    }
};