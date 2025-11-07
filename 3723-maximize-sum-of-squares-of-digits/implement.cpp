class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        while (sum - 9 >= 0) {
            ans += '9';
            sum -= 9;
        }
        if (sum) ans += (char)(sum + '0');
        if (ans.size() > num) return "";
        while (ans.size() < num) {
            ans += '0';
        }
        return ans;
    }
};