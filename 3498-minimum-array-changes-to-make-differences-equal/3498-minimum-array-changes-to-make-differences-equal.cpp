class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n/2; i++)
            mp[abs(nums[i]-nums[n-i-1])]++;
        vector<int> v;
        for(auto it : mp)
            v.push_back(it.first);
        auto cmp = [&](int a, int b){
            return mp[a] > mp[b];
        };
        sort(v.begin(), v.end(), cmp);
        int ans = INT_MAX;
        for(int j = 0; j < min((int)v.size(), 10); j++){
            int t = v[j];
            int cnt = 0;
            for(int i = 0; i < n/2; i++){
                if(abs(nums[i]-nums[n-i-1]) != t){
                    if(t+nums[n-i-1] >= 0 && t+nums[n-i-1] <= k)
                        cnt++;
                    else if(-t+nums[n-i-1] >= 0 && -t+nums[n-i-1] <= k)
                        cnt++;
                    else if(nums[i]-t >= 0 && nums[i]-t <= k)
                        cnt++;
                    else if(nums[i]+t >= 0 && nums[i]+t <= k)
                        cnt++;
                    else
                        cnt += 2;
                }
            }
            ans = min(ans, cnt);
        }
        return ans;
    }
};