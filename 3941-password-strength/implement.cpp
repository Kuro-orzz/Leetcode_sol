class Solution {
public:
    int passwordStrength(string password) {
        int n = password.size();
        vector<int> vis(256, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (vis[password[i]]) continue;
            if (password[i] >= 'a' && password[i] <= 'z') {
                ans++;
            } else if (password[i] >= 'A' && password[i] <= 'Z') {
                ans += 2;
            } else if (isdigit(password[i])) {
                ans += 3;
            } else if (password[i]=='!' || password[i]=='@' || password[i]=='#' || password[i] == '$') {
                ans += 5;
            }
            vis[password[i]] = 1;
        }
        return ans;
    }
};