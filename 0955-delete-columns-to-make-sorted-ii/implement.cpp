class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<int> lexico(n, 0);
        int ans = 0;
        for (int j = 0; j < m; j++) {
            vector<int> save;
            bool isDel = false;
            for (int i = 1; i < n; i++) {
                if (lexico[i]) continue;
                if (strs[i-1][j] > strs[i][j]) {
                    ans++;
                    isDel = true;
                    break;
                } else if (strs[i-1][j] < strs[i][j]) {
                    save.push_back(i);
                }
            }
            if (!isDel) {
                for (int x : save) lexico[x] = 1;
            }
        }
        return ans;
    }
};