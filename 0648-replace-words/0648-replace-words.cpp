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
    int query(string &s){
        node* u = root;
        for(int i = 0; i < s.size(); i++){
            int k = s[i]-'a';
            if(!u->child[k])
                return 0;
            u = u->child[k];
            if(u->isEnd)
                return i+1;
        }
        return 0;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        int n = dictionary.size();
        for(int i = 0; i < n; i++)
            add(dictionary[i]);
        stringstream s(sentence);
        string x;
        string ans = "";
        while(s >> x){
            if(!query(x))
                ans += x;
            else{
                int t = query(x);
                ans += x.substr(0, t);
            }
            ans += ' ';
        }
        return ans.substr(0, ans.size()-1);
    }
};