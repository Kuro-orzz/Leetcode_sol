class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        vector<int> rev_nums;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            string s = to_string(nums[i]);
            reverse(s.begin(), s.end());
            rev_nums.push_back(stoi(s));
            mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (mp.find(rev_nums[i]) == mp.end()) continue;
            auto it = upper_bound(mp[rev_nums[i]].begin(), mp[rev_nums[i]].end(), i);
            if (it != mp[rev_nums[i]].end()) {
                ans = min(ans, abs(*it - i));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};