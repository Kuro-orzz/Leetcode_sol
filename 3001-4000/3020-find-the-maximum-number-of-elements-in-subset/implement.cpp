class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        map<long long, int> mp;
        for (int &x : nums) {
            mp[x]++;
        }
        int ans = 0;
        for (auto &it : mp) {
            long long x = it.first;
            if (x == 1) {
                ans = max(ans, it.second - (it.second+1) % 2);
                continue;
            }
            int cnt = 0;
            while (mp[x] >= 2) {
                cnt += 2;
                x *= x;
            }
            if (mp[x] >= 1) {
                ans = max(ans, cnt + 1);
            } else {
                ans = max(ans, cnt - 1);
            }
        }
        return ans;
    }
};