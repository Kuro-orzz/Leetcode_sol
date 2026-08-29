#define ll long long

class Solution {
public:
    int countDigitOne(int n) {
        int ans = 0;
        for (ll i = 1; i <= n; i *= 10) {
            ll div = i * 10;
            ans += (n / div) * i + min(max(n % div -i + 1, 0ll), i);
        }
        return ans;
    }
};