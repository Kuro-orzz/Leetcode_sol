class Solution {
public:
    long long removeZeros(long long n) {
        string s = to_string(n);
        string tmp = "";
        for (char c : s) if (c != '0') tmp += c;
        return stoll(tmp);
    }
};