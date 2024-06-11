#define pii pair<int, int>
#define fi first
#define se second
class Solution {
public:
    struct node{
        node* child[26];
        int isEnd;
        node(){
            memset(child, 0, sizeof(child));
            isEnd = 0;
        }
    };
    node* root = new node();
    void add(string &s){
        node* u = root;
        for(int i = 0; i < s.size(); i++){
            int k = s[i]-'a';
            if(!u->child[k])
                u->child[k] = new node();
            u = u->child[k];
        }
        u->isEnd = 1;
    }
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    unordered_set<string> ans;
    vector<vector<int>> vis;
    bool isValid(int n, int m, pii u){
        return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m;
    }
    void dfs(int n, int m, pii v, node* r, vector<vector<char>> &board, vector<char> &t){
        node* u = r;
        vis[v.fi][v.se] = 1;
        t.push_back(board[v.fi][v.se]);
        u = u->child[board[v.fi][v.se]-'a'];
        if(u->isEnd){
            string s = "";
            for(char c : t)
                s += c;
            ans.insert(s);
        }
        for(int i = 0; i < 4; i++){
            pii pos = {v.fi+dx[i], v.se+dy[i]};
            if(isValid(n, m, pos) && !vis[pos.fi][pos.se]){
                if(u->child[board[pos.fi][pos.se]-'a'])
                    dfs(n, m, pos, u, board, t);
            }
        }
        vis[v.fi][v.se] = 0;
        t.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(string &s : words)
            add(s);
        int n = board.size();
        int m = board[0].size();
        vis.resize(n, vector<int>(m, 0));
        vector<char> t;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(root->child[board[i][j]-'a']){
                    dfs(n, m, {i, j}, root, board, t);
                }
            }
        vector<string> res;
        for(string s : ans)
            res.push_back(s);
        return res;
    }
};