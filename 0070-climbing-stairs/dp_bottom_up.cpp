class Solution {
public:
    int climbStairs(int n) {
        int fib1 = 1;
        int fib2 = 1;
        int tmp;
        for(int i = 2; i <= n; i++){
            tmp = fib1 + fib2;
            fib2 = fib1;
            fib1 = tmp;
        }
        return fib1;
    }
};