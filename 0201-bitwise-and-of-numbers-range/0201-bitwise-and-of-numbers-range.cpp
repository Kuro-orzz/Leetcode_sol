#pragma GCC optimize("O3, unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
static const bool __io_boost = [](){
    cin.tie(nullptr); cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);      
}();

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(left < right){
            right = right&~(1<<__builtin_ctz(right));
        }
        return right;
    }
};