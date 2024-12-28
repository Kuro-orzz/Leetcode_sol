class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans = {0, INT_MAX};
        set<tuple<int, int, int>> s;
        for(int i = 0; i < nums.size(); i++)
            s.insert({nums[i][0], i, 0});
        while(true){
            tuple<int, int, int> mn = *s.begin();
            tuple<int, int, int> mx = *prev(s.end());
            s.erase(s.begin());
            if(ans[1]-ans[0] > get<0>(mx)-get<0>(mn)){
                ans[0] = get<0>(mn);
                ans[1] = get<0>(mx);
            }
            if(get<2>(mn)+1 == nums[get<1>(mn)].size())
                break;
            s.insert(make_tuple(nums[get<1>(mn)][get<2>(mn)+1], get<1>(mn), get<2>(mn)+1));
        }
        return ans;
    }
};