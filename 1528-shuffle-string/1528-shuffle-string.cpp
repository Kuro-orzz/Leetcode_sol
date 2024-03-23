class Solution {
public:
    static bool cmp(pair<char, int> a, pair<char, int> b){
        return a.second < b.second;
    }
    string restoreString(string s, vector<int>& indices) {
        int n = s.length();
        pair<char, int> p[n];
        for(int i = 0; i < n; i++)
            p[i] = {s[i], indices[i]};
        sort(p, p+n, (cmp));
        string ans = "";
        for(int i = 0; i < n; i++)
            ans += p[i].first;
        return ans;
    }
};