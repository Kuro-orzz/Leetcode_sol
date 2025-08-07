class Solution {
public:
    vector<vector<string>> v;
    vector<string> ans;

    bool isSubFolder(vector<string> &a, vector<string> &b) {
        if (a.size() > b.size()) return false;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        sort(folder.begin(), folder.end());
        v.resize(n);
        for (int i = 0; i < n; i++) {
            stringstream ss(folder[i]);
            string tmp;
            while (getline(ss, tmp, '/')) {
                if (tmp == "") continue;
                v[i].push_back(tmp);
            }
        }
        int pos = 0;
        ans.push_back(folder[0]);
        for (int i = 1; i < n; i++) {
            if (isSubFolder(v[pos], v[i])) continue;
            pos = i;
            ans.push_back(folder[i]);
        }
        return ans;
    }
};