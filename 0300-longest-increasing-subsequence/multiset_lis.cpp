class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        multiset<int> ms;
        for(int x : nums){
            auto it = ms.lower_bound(x);
            if(it != ms.end())
                ms.erase(it);
            ms.insert(x);
        }
        return ms.size();
    }
};