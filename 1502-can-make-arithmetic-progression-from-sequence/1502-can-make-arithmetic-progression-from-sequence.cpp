#pragma GCC optimize("O3, unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
static const bool __io_boost = [](){
    cin.tie(nullptr); cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);      
}();

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if(arr.size() == 2)
            return true;
        sort(arr.begin(), arr.end());
        int d = arr[1]-arr[0];
        for(int i = 2; i < arr.size(); i++)
            if(arr[i]-arr[i-1] != d)
                return false;
        return true;
    }
};