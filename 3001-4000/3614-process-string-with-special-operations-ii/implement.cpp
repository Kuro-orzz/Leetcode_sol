#define ll long long

class Solution {
public:
    char processStr(string s, long long k) {
        string x = "";
        ll count = 0;
        for (char &c : s) {
            if (isalpha(c)) {
                count++;
                x += c;
            } else if (c == '*') {
                if (count > 0) {
                    count--;
                    x += c;
                }
            } else if (c == '#') {
                count *= 2;
                x += c;
            } else if (c == '%') {
                x += c;
            }
        }
        int n = x.size();
        if (k >= count) return '.';
        for (int i = n-1; i >= 0; i--) {
            if (x[i] == '%') {
                k = count - k -1;
            } else if (x[i] == '#') {
                if (k >= count / 2) {
                    k -= count /2;
                }
                count /= 2;
            } else if (x[i] == '*') {
                count++;
            } else if (isalpha(x[i])) {
                count--;
                if (k == count) return x[i];
            }
        }
        return '.';
    }
};