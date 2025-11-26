class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int res = 0;
        int cur = 0;
        for (int i = 0; i < k; i++) {
            cur = cur * 10 + 1;
            cur %= k;
            res++;
            if (cur % k == 0) return res;
        }
        return -1;
    }
};