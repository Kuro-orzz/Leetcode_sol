class Solution {
public:
    long long sumAndMultiply(int n) {
        string x = to_string(n);
        int sum = 0;
        long long num = 0;
        for (char &c : x) {
            if (c == '0') continue;
            sum += c - '0';
            num = num * 10 + (c - '0');
        }
        return num * sum;
    }
};