class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string s;
        vector<string> p;
        while (getline(ss, s, '/')) {
            if (s == ".") continue;
            else if (s == "") {
                if (p.empty()) p.push_back(s);
            } else if (s == "..") {
                if (!p.empty()) p.pop_back();
            } else if (s != "") {
                p.push_back(s);
            }
        }
        string ans = "/";
        for (string &t : p) {
            if (t == "") continue;
            else ans += t + "/";
        }
        if (ans.size() > 1) ans.pop_back();
        return ans;
    }
};