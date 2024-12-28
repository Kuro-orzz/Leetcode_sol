class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        for(int i = 0; i < min(k, (int)nums.size()); i++){
            if(s.find(nums[i]) != s.end())
                return true;
            s.insert(nums[i]);
        }
        for(int i = min(k, (int)nums.size()); i < nums.size(); i++){
            if(s.find(nums[i]) != s.end())
                return true;
            s.insert(nums[i]);
            s.erase(nums[i-k]);
        }
        return false;
    }
};