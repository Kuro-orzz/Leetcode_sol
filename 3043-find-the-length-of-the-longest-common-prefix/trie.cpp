struct Node {
    Node *child[10];
    bool isEnd;

    Node() {
        memset(child, 0, sizeof child);
        isEnd = false;
    }
};

class Trie {
public:
    Node *r = new Node();

    Trie() {}

    void add(const string &s) {
        Node *u = r;
        for (size_t i = 0; i < s.size(); i++) {
            int k = s[i] - '0';
            if (!u->child[k]) {
                u->child[k] = new Node();
            }
            u = u->child[k];
        }
        u->isEnd = true;
    }

    int search(const string &s) {
        Node *u = r;
        for (size_t i = 0; i < s.size(); i++) {
            int k = s[i] - '0';
            if (!u->child[k]) {
                return i;
            }
            u = u->child[k];
        }
        return (int)s.size();
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        Trie trie;
        for (int i = 0; i < m; i++) {
            trie.add(to_string(arr2[i]));
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, trie.search(to_string(arr1[i])));
        }
        return ans;
    }
};