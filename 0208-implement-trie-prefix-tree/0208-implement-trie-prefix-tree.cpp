class Trie {
public:
    int child[300000][26];
    bool isEnd[300000];
    int cnt = 0;
    Trie() {
        for(int i = 0; i < 300000; i++)
            memset(child[i], 0, sizeof(child[i]));
        memset(isEnd, 0, sizeof(isEnd));
        cnt = 0;
    }
    
    void insert(string word) {
        int u = 0;
        for(int i = 0; i < word.size(); i++){
            int k = word[i]-'a';
            if(!child[u][k])
                child[u][k] = ++cnt;
            u = child[u][k];
        }
        isEnd[u] = 1;
    }
    
    bool search(string word) {
        int u = 0;
        for(int i = 0; i < word.size(); i++){
            int k = word[i]-'a';
            if(!child[u][k])
                return false;
            u = child[u][k];
        }
        return isEnd[u];
    }
    
    bool startsWith(string prefix) {
        int u = 0;
        for(int i = 0; i < prefix.size(); i++){
            int k = prefix[i]-'a';
            if(!child[u][k])
                return false;
            u = child[u][k];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */