class Solution {
public:
    int child[100001][26];
    int isEnd[100001];
    int cnt = 0;
    void add(string &s){
        int u = 0;
        for(int i = 0; i < s.size(); i++){
            int k = s[i]-'a';
            if(!child[u][k])
                child[u][k] = ++cnt;
            u = child[u][k];
        }
        isEnd[u] = 1;
    }
    int query(string &s){
        int u = 0;
        int tail = 0;
        for(int i = 0; i < s.size(); i++){
            int k = s[i]-'a';
            if(!child[u][k])
                break;
            u = child[u][k];
            if(isEnd[u]){
                tail = i+1;
                break;
            }
        }
        return tail;
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