class Solution {
public:
    static bool cmp (int &a, int &b) {
        return abs(a) > abs(b);
    }
    
    long long maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> nonZero;
        for (int x : nums) {
            if (!x) continue;
            nonZero.push_back(x);
        }
        if (nonZero.size() < 2) return 0;
        sort(nonZero.begin(), nonZero.end(), cmp);
        return llabs(1ll * nonZero[0] * nonZero[1] * 100000);
    }
};