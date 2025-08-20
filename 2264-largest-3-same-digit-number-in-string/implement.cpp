class Solution {
public:
    string largestGoodInteger(string num) {
        int mx = -1;
        for (int i = 2; i < num.size(); i++) {
            if (num[i-2] == num[i] && num[i-1] == num[i]) {
                mx = max(mx, stoi(num.substr(i-2, 3)));
            }
        }
        if (mx == -1) return "";
        if (mx == 0) return "000";
        return to_string(mx);
    }
};