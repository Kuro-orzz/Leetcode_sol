#pragma GCC optimize("O3, unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
static const bool __io_boost = [](){
    cin.tie(nullptr); cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);      
}();

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive;
        vector<int> negative;
        for(int x : nums)
            if(x > 0)
                positive.push_back(x);
            else
                negative.push_back(x);
        vector<int> ans;
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 0; i < nums.size(); i++)
            if(i % 2 == 0){
                ans.push_back(positive[cnt1]);
                cnt1++;
            }
            else{
                ans.push_back(negative[cnt2]);
                cnt2++;
            }
        return ans;
    }
};