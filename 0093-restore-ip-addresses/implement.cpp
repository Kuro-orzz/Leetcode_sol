class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> ans;
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                for (int k = 1; k <= 3; k++) {
                    if (i + j + k >= n || n - i - j - k > 3) continue;
                    if (s[0] == '0' && i > 1) continue;
                    if (s[i] == '0' && j > 1) continue; 
                    if (s[i+j] == '0' && k > 1) continue;
                    if (s[i+j+k] == '0' && n-i-j-k > 1) continue;
                    int f1 = stoi(s.substr(0, i));
                    int f2 = stoi(s.substr(i, j));
                    int f3 = stoi(s.substr(i+j, k));
                    int f4 = stoi(s.substr(i+j+k));
                    if (f1 > 255 || f2 > 255 || f3 > 255 || f4 > 255) continue;
                    ans.push_back(s.substr(0, i) + '.' + s.substr(i, j) + '.' + s.substr(i+j, k) + '.' + s.substr(i+j+k));
                }
            }
        }
        return ans;
    }
};