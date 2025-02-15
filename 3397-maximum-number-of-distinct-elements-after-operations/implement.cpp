class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int mn = INT_MIN;
        sort(nums.begin(), nums.end());
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            for(int j = max(mn, nums[i]-k); j <= nums[i]+k; j++){
                mn = j;
                if(!mp.count(j)){
                    mp[j]++;
                    break;
                }
            }
        }
        return mp.size();
    }
};