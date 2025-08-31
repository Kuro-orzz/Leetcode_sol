class Solution {
public:
    long long flowerGame(int n, int m) {
        // even + odd
        // odd + even
        int even_X = n / 2;
        int odd_X = n - even_X;
        int even_y = m / 2;
        int odd_y = m - even_y;
        return 1ll * even_X * odd_y + 1ll * odd_X * even_y;
    }
};