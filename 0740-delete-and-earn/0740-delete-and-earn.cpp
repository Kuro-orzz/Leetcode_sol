class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)
            mp[nums[i]]++;
        vector<int> v;
        for(auto it : mp)
            v.push_back(it.first);
        sort(v.begin(), v.end());
        vector<int> dp(v.size()+1, 0);
        auto val = [&](int a){return a*mp[a];};
        dp[1] = v[0]*mp[v[0]];
        for(int i = 2; i <= v.size(); i++){
            if(i-2 >= 0 && v[i-1]-1 == v[i-2])
                dp[i] = max(dp[i-1], dp[i-2]+val(v[i-1]));
            else
                dp[i] = dp[i-1]+val(v[i-1]);
        }
        return dp[v.size()];
    }
};