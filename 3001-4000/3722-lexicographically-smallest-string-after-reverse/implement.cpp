class Solution {
public:
    string lexSmallest(string s) {
        int n = s.size();
        vector<string> v;
        for (int k = 1; k <= n; k++) {
            string tmp = s;
            reverse(tmp.begin(), tmp.begin() + k);
            v.push_back(tmp);
            tmp = s;
            reverse(tmp.begin() + n - k, tmp.end());
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());
        return v[0];
    }
};