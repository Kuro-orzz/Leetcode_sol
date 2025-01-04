class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int, int>> v(26, {0, 0});
        for(int i = 0; i < s.size(); i++){
            if(!v[s[i]-'a'].first)
                v[s[i]-'a'].first = i+1;
            else v[s[i]-'a'].second = i+1;
        }
        int ans = 0;
        for(int i = 0; i < 26; i++){
            if(!v[i].second) continue;
            unordered_set<char> st;
            for(int j = v[i].first; j < v[i].second-1; j++)
                st.insert(s[j]);
            ans += st.size();
        }
        return ans;
    }   
};