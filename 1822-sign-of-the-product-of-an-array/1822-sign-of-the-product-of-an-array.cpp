#pragma GCC optimize("O3, unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
static const bool __io_boost = [](){
    cin.tie(nullptr); cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);      
}();

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negative = 0;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] == 0)
                return 0;
            else if(nums[i] < 0)
                negative++;
        if(negative % 2 == 1)
            return -1;
        else
            return 1;
    }
};