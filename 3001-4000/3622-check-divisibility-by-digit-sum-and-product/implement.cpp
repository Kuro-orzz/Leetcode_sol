class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, prod = 1;
        int tmp = n;
        while (tmp) {
            sum += tmp % 10;
            prod *= tmp % 10;
            tmp /= 10;
        }
        return n % (sum + prod) == 0;
    }
};