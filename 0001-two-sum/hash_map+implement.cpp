class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]].push_back(i + 1);
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if(target-nums[i] != nums[i] && mp[target-nums[i]].size() != 0){
                res.push_back(mp[nums[i]][0]-1);
                res.push_back(mp[target-nums[i]][0]-1);
                break;
            }
            if(target-nums[i] == nums[i] && mp[target-nums[i]].size() > 1){
                res.push_back(mp[nums[i]][0]-1);
                res.push_back(mp[nums[i]][1]-1);
                break;
            }
        }
        return res;
    }
};