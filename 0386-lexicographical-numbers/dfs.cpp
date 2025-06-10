class Solution {
public:
    int n;
    vector<int> ans;

    void dfs(string &s) {
        if (s != "") ans.push_back(stoi(s));
        for (char c = '0'; c <= '9'; c++) {
            s += c;
            int t = stoi(s);
            if (t >= 1 && t <= n) dfs(s);
            s.pop_back();
        }
    }

    vector<int> lexicalOrder(int n) {
        this->n = n;
        string s = "";
        dfs(s);
        return ans;
    }
};