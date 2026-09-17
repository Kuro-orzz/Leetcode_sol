class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = 1e9, odd = 0, even = 0;
        for (int x : nums1) {
            mn = min(mn, x);
            if (x % 2) odd++;
            else even++;
        }
        if (mn % 2 == 0) {
            if (odd) return false;
        }
        return true;
    }
};