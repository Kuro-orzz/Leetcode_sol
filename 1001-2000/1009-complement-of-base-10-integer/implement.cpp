class Solution {
public:
    int bitwiseComplement(int n) {
        if (!n) return 1;
        int k = __builtin_clz(n);
        for (int i = 0; i < 32 - k; i++) {
            n = n ^ (1 << i);
        }
        return n;
    }
};