class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int &x : nums) {
            int pos = __builtin_ctz(~x);
            if (!pos) ans.push_back(-1);
            else ans.push_back(x - (1 << (pos-1)));
        }
        return ans;
    }
};