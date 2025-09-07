class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        string s = to_string(n), x;
        int memo = 0;
        while (!s.empty()) {
            int k = s.back() - '0'; s.pop_back();
            if (memo) k--;
            if (k <= 1) {
                memo = 1;
                if (!s.empty()) x += '2';
            } else {
                memo = 0;
                x += '1';
            }
        }
        reverse(x.begin(), x.end());
        ans.push_back(stoi(x));
        ans.push_back(n - stoi(x));
        return ans;
    }
};