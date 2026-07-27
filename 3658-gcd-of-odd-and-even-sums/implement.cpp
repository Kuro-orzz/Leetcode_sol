#define ll long long

class Solution {
public:
    ll GCD(ll a, ll b) { return (!b ? a : GCD(b, a % b)); }

    int gcdOfOddEvenSums(int n) {
        int sumOdd = n * (1 + 1 + 2 * (n-1)) / 2;
        int sumEven = n * (2 + 2 + 2 * (n-1)) / 2;
        return GCD(sumOdd, sumEven);
    }
};