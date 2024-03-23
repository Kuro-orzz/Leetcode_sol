class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, pair<int, int>> mp;
        int cnt[2];
        cnt[0] = cnt[1] = 0;
        int ans = 0;
        mp[0] = {0, 0};
        for(int i = 0; i < nums.size(); i++){
            cnt[nums[i]]++;
            if(cnt[0] == cnt[1])
                mp[cnt[1]-cnt[0]].second = i+1;
            else if(mp[cnt[1]-cnt[0]].first != 0)
                mp[cnt[1]-cnt[0]].second = i+1;
            else
                mp[cnt[1]-cnt[0]].first = i+1;
        }
        for(auto it : mp)
            ans = max(ans, it.second.second-it.second.first);
        return ans;
    }
};