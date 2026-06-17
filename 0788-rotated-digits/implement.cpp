class Solution {
public:
    bool rotate(string s) {
        bool flag = false;
        for (char &c : s) {
            if (c == '2' || c == '5' || c == '6' || c == '9') {
                flag = true;
            } else if (c == '3' || c == '4' || c == '7') {
                return false;
            }
        }
        return flag;
    }

    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (rotate(to_string(i))) ans++;
        }
        return ans;
    }
};