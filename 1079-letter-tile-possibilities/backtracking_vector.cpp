class Solution {
public:
    vector<int> cnt;
    unordered_set<string> st;

    void backtrack(string &s){
        if(st.count(s)) return;
        st.insert(s);
        for(int i = 0; i < 26; i++){
            if(!cnt[i]) continue;
            s += (char)(i+'A');
            cnt[i]--;
            backtrack(s);
            s.pop_back();
            cnt[i]++;
        }
    }

    int numTilePossibilities(string tiles) {
        cnt.resize(26, 0);
        for(char c : tiles)
            cnt[c-'A']++;
        string s = "";
        backtrack(s);
        return st.size()-1;          
    }
};