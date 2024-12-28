class Trie {
public:
    struct node{
        node* child[26];
        int isEnd;
        node(){
            memset(child, 0, sizeof(child));
            isEnd = 0;
        }
    };
    node* root;
    Trie() {
        root = new node;
    }
    
    void insert(string word) {
        node* u = root;
        for(int i = 0; i < word.size(); i++){
            int k = word[i]-'a';
            if(!u->child[k])
                u->child[k] = new node();
            u = u->child[k];
        }
        u->isEnd = 1;
    }
    
    bool search(string word) {
        node* u = root;
        for(int i = 0; i < word.size(); i++){
            int k = word[i]-'a';
            if(!u->child[k])
                return false;
            u = u->child[k];
        }
        return u->isEnd;
    }
    
    bool startsWith(string prefix) {
        node* u = root;
        for(int i = 0; i < prefix.size(); i++){
            int k = prefix[i]-'a';
            if(!u->child[k])
                return false;
            u = u->child[k];
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