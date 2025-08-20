class Solution {
public:
    vector<string> validStrings(int n) {
        if (n == 1) return { "0", "1" };
        vector<string> ans;
        for (int i = 1; i < (1 << n); i++) {
            bitset<20> bin(i);
            string s = bin.to_string().substr(20-n);
            bool flag = true;
            for (int i = 1; i < (int)s.size(); i++) {
                if (s[i-1] == '0' && s[i] == '0') {
                    flag = false;
                }
            }
            if (flag) ans.push_back(s);
        }
        return ans;
    }
};