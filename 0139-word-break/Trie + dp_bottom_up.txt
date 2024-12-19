class Solution {
public:
    struct Trie{
        struct Node{
            Node* child[26];
            bool isEnd;
            Node(){
                memset(child, 0, sizeof(child));
                isEnd = false;
            }
        };

        Node* r;
        
        Trie(){
            r = new Node();
        }

        void add(string& s){
            Node* u = r;
            for(int i = 0; i < s.size(); i++){
                int k = s[i]-'a';
                if(!u->child[k])
                    u->child[k] = new Node();
                u = u->child[k];
            }
            u->isEnd = true;
        }

        void search(string& s, int pos, vector<int>& dp){
            Node* u = r;
            for(int i = pos; i < s.size(); i++){
                int k = s[i]-'a';
                if(!u->child[k])
                    return;
                u = u->child[k];
                if(u->isEnd)
                    dp[i+1] = 1;
            }
        }
    };

    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for(int i = 0; i < wordDict.size(); i++)
            trie.add(wordDict[i]);
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        for(int i = 0; i < s.size(); i++){
            if(!dp[i]) continue;
            trie.search(s, i, dp);
        }
        return dp[s.size()];
    } 
};