class Solution {
public:
    bool check(int n, int t) {
        int res = 1;
        while (n) {
            res *= n % 10;
            n /= 10;
        }
        return res % t == 0;
    }

    int smallestNumber(int n, int t) {
        for (int i = n; ; i++) {
            if (check(i, t)) return i;
        }
        return -1;
    }
};