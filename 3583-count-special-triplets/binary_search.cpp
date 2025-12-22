#define all(x) (x).begin(),(x).end()

class Solution {
public:
    int mod = 1e9 + 7;

    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> cnt(1e5 + 6);
        for (int i = 0; i < n; i++) {
            cnt[nums[i]].push_back(i);
        }
        int ans = 0;
        for (int i = 0; i <= 1e5; i++) {
            for (int x : cnt[i]) {
                if (i * 2 > 1e5 || !cnt[i*2].size()) continue;
                auto it_left = lower_bound(all(cnt[i*2]), x);
                if (it_left == cnt[i*2].begin()) continue;
                it_left = prev(it_left);
                auto it_right = upper_bound(all(cnt[i*2]), x);
                if (it_right == cnt[i*2].end()) continue;
                int left = it_left - cnt[i*2].begin() + 1;
                int right = cnt[i*2].size() - (it_right - cnt[i*2].begin());
                ans = (ans + 1ll * left * right) % mod;
            }
        }
        return ans;
    }
};