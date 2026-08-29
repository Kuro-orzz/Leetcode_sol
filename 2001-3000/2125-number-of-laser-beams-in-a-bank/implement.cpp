class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int row = bank.size();
        int col = bank[0].size();
        int ans = 0;
        vector<string> v;
        for (int i = 0; i < row; i++) {
            if (bank[i] != string(col, '0')) v.push_back(bank[i]);
        }
        for (int i = 1; i < v.size(); i++) {
            int cnt1 = 0, cnt2 = 0;
            for (int j = 0; j < col; j++) {
                if (v[i-1][j] == '1') cnt1++;
                if (v[i][j] == '1') cnt2++;
            }
            ans += cnt1 * cnt2;
        }
        return ans;
    }
};