class Solution {
public:
    char kthCharacter(int k) {
        long long t = 1ll << __lg(k);
        if (t < k) t *= 2;
        int cnt = 0;
        long long l = 1, r = t;
        int cur = __lg(t);
        while (l < r) {
            cur--;
            long long mid = (l + r) / 2;
            if (k > mid) {
                cnt++;
                k -= mid;
            }
            r = mid;
        }
        return 'a' + (cnt % 26);
    }
};
