class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long i = 0; i*i <= c; i++){
            long long a = i;
            long long b = sqrt(c-a*a);
            if(b*b == c-a*a)
                return true;
        }
        return false;
    }
};