class Solution {
public:
    unordered_map<char, int> mp;
    unordered_set<string> st;

    void backtrack(string &s){
        if(st.count(s)) return;
        st.insert(s);
        for(auto &it : mp){
            if(!it.second) continue;
            s += it.first;
            it.second--;
            backtrack(s);
            s.pop_back();
            it.second++;
        }
    }

    int numTilePossibilities(string tiles) {
        for(char c : tiles)
            mp[c]++;
        string s = "";
        backtrack(s);
        return st.size()-1;          
    }
};