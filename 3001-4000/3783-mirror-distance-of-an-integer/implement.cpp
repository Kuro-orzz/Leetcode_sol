class Solution {
public:
    int mirrorDistance(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        int rev_n = stoll(s);
        return abs(n - rev_n);
    }
};