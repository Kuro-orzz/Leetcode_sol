class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(32, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 32; j++) {
                cnt[j] += nums[i] >> j & 1;
            }
        }
        string s = "";
        for (int i = 31; i >= 0; i--) {
            s += to_string(cnt[i] % 3);
        }
        return bitset<32>(s).to_ulong();
    }
};