#define ll long long

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int i = 0; i <= 60; i++) {
            ll target = num1 - 1ll * i * num2;
            if (target < i) return -1;
            if (__builtin_popcountll(target) <= i) {
                return i;
            }
        }
        return -1;
    }
};