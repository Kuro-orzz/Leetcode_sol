// https://stackoverflow.com/questions/4068033/add-two-integers-using-only-bitwise-operators

class Solution {
public:
    int getSum(int a, int b) {
        int carry = a & b;
        int ans = a ^ b;
        while (carry) {
            int shiftedcarry = carry << 1;
            carry = ans & shiftedcarry;
            ans ^= shiftedcarry;
        }
        return ans;
    }
};