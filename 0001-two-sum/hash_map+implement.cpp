#define pii pair<int, int>
#define fi first
#define se second
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        for (auto &[x, y] : mp) {
            if (x * 2 == target && y.size() > 1)
                return {y[0], y[1]};
            else if (x * 2 != target && mp.count(target-x))
                return {y[0], mp[target-x][0]};
        }
        return {};
    }
};