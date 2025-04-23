class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long mx = 0, mn = 0;
        long long cur = 0;
        for (int i = 0; i < differences.size(); i++) {
            cur += differences[i];
            mx = max(mx, cur);
            mn = min(mn, cur);
        }
        return max(0ll, upper-lower+1-mx+mn);
    }
};