class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        for (int i = 0; i < (int)s.size(); i +=k) {
            ans.push_back(s.substr(i, k));
            if ((int)ans.back().size() < k) {
                ans.back() += string(k-(int)ans.back().size(), fill);
            }
        }
        return ans;
    }
};