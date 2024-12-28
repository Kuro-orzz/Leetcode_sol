class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0)
            return false;
        if(log2(n) == (int)__lg(n))
            return true;
        else
            return false;
    }
};