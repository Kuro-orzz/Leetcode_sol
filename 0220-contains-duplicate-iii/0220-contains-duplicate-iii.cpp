class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<int> s;
        for(int i = 0; i < indexDiff; i++){
            auto it = s.lower_bound(nums[i]);
            if(!s.empty() && it != s.end() && abs(*it-nums[i]) <= valueDiff)
                return true;
            if(!s.empty() && prev(it) != s.end() && abs(*prev(it)-nums[i]) <= valueDiff)
                return true;
            s.insert(nums[i]);
        }
        for(int i = indexDiff; i < nums.size(); i++){
            auto it = s.lower_bound(nums[i]);
            if(!s.empty() && it != s.end() && abs(*it-nums[i]) <= valueDiff)
                return true;
            if(!s.empty() && prev(it) != s.end() && abs(*prev(it)-nums[i]) <= valueDiff)
                return true;
            s.erase(nums[i-indexDiff]);
            s.insert(nums[i]);
        }
        return false;
    }
};