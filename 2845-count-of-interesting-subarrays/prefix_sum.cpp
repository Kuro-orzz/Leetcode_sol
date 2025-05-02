class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        long long cnt = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % modulo == k) cnt++;
            ans += mp[(cnt-k+modulo)%modulo];
            mp[cnt % modulo]++;
        }
        return ans;
    }
};