class Solution {
public:
    char solve(int k, int n, int cnt) {
        if (k > 1 && k == n / 2 + 1) {
            if (cnt & 1) return '0';
            else return '1';
        } else if (k == 1) {
            if (cnt & 1) return '1';
            else return '0';
        }
        if (k < n/2 + 1) return solve(k, (n-1) / 2, cnt);
        return solve(n-k+1, (n-1) / 2, cnt + 1);
    }

    char findKthBit(int n, int k) {
        int len = (1 << n) - 1;
        while ((len - 1) / 2 >= k) len = (len - 1) / 2;
        return solve(k, len, 0);
    }
};