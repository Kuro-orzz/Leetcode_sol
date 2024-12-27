class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long long pre = 0;
        multiset<long long> ms;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            pre += nums[i];
            auto it1 = ms.lower_bound(pre-upper);
            auto it2 = ms.upper_bound(pre-lower);
            ans += distance(it1, it2);
            if(pre >= lower && pre <= upper) ans++;
            ms.insert(pre);
        }
        return ans;
    }
};