class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        map<int, vector<int>> mp;
        for (int i = 0; i < (int)groupSizes.size(); i++) {
            mp[groupSizes[i]].push_back(i);
        }
        for (auto [sz, v] : mp) {
            ans.push_back({});
            for (int x : v) {
                if (ans.back().size() == sz) {
                    ans.push_back({});
                }
                ans.back().push_back(x);
            }
        }
        return ans;
    }
};