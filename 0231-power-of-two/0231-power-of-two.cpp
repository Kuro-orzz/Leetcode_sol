class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n != 0 && log2(n) == 31- __builtin_clz(n))
            return true;
        return false;
    }
};