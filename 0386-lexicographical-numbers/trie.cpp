class Solution {
public:
    struct Node{
        Node* child[10];
        bool isEnd;
        Node(){
            memset(child, 0, sizeof(child));
            isEnd = false;
        }
    };
    Node* r = new Node();
    vector<int> ans;
    void add(string& s){
        Node* u = r;
        for(int i = 0; i < s.size(); i++){
            int k = s[i]-'0';
            if(!u->child[k])
                u->child[k] = new Node();
            u = u->child[k];
        }
        u->isEnd = true;
    }
    void travel(Node* r, string s){
        Node* u = r;
        if(u->isEnd) 
            ans.push_back(stoi(s));
        for(int i = 0; i < 10; i++){
            if(u->child[i])
                travel(u->child[i], s + to_string(i));
        }
    }
    vector<int> lexicalOrder(int n) {
        for(int i = 1; i <= n; i++){
            string x = to_string(i); 
            add(x);
        }
        travel(r, "");      
        return ans;
    }
};