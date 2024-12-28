class WordDictionary {
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
    WordDictionary() {
        root = new node();
    }
    
    void addWord(string word) {
        node* u = root;
        for(int i = 0; i < word.size(); i++){
            int k = word[i]-'a';
            if(!u->child[k])
                u->child[k] = new node();
            u = u->child[k];
        }
        u->isEnd = 1;
    }
    
    bool find(string &word, int t, node* r){
        node* u = r;
        for(int i = t; i < word.size(); i++){
            if(word[i] == '.'){
                for(int j = 0; j < 26; j++){
                    if(u->child[j]){
                        if(find(word, i+1, u->child[j]))
                            return true;
                    }
                }
                return false;
            }
            int k = word[i]-'a';
            if(!u->child[k])
                return false;
            u = u->child[k];
        }
        return u->isEnd;
    }

    bool search(string word) {
        return find(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */