class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k) return false;
        vector<int> v(26, 0);
        for(char c : s)
            v[c-'a']++;
        int cnt = 0;
        for(int i = 0; i < 26; i++)
            if(v[i] % 2) cnt++;
        return cnt <= k;
    }
};