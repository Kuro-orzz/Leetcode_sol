#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    static bool cmp(pii &a, pii &b) {
        if (a.se != b.se) return a.se > b.se;
        return a.fi > b.fi;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int l = 0, r = 0;
        vector<int> cnt(51, 0), ans;
        while (r < n) {
            cnt[nums[r++]]++;
            // i+k-1 - i == 0
            if (r - l == k) {
                vector<pii> freq;
                for (int i = 1; i <= 50; i++) {
                    if (!cnt[i]) continue;
                    freq.push_back({i, cnt[i]});
                }
                sort(freq.begin(), freq.end(), cmp);
                int sum = 0;
                for (int i = 0; i < min((int)freq.size(), x); i++) {
                    sum += freq[i].fi * freq[i].se;
                }
                ans.push_back(sum);
                cnt[nums[l++]]--;
            }
        }
        return ans;
    }
};