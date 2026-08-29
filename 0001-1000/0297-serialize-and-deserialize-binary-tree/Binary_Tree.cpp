/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serializedTree = "";
        if (!root) return serializedTree;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node) {
                serializedTree += to_string(node->val) + "#";
                q.push(node->left);
                q.push(node->right);
            } else {
                serializedTree += "null#";
            }
        }
        return serializedTree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        vector<string> v;
        string tmp = "";
        for (char c : data) {
            if (c == '#') {
                v.push_back(tmp);
                tmp = "";
            } else {
                tmp += c;
            }
        }
        TreeNode* root = new TreeNode(stoi(v[0]));
        queue<TreeNode*> q;
        q.push(root);
        for (int i = 1; i < v.size(); ) {
            TreeNode* newNode = q.front(); q.pop();
            if (v[i] != "null") {
                newNode->left = new TreeNode(stoi(v[i]));
                q.push(newNode->left);
            }
            i++;
            if (i < v.size() && v[i] != "null") {
                newNode->right = new TreeNode(stoi(v[i]));
                q.push(newNode->right);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));