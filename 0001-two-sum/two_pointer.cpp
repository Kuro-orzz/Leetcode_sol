#define pii pair<int, int>
#define fi first
#define se second
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pii> v;
        for (int i = 0; i < nums.size(); i++) {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        int p1 = 0, p2 = nums.size()-1;
        while(p1 < p2) {
            if (v[p1].fi + v[p2].fi < target) p1++;
            else if (v[p1].fi + v[p2].fi > target) p2--;
            else return {v[p1].se, v[p2].se};
        }
        return {};
    }
};