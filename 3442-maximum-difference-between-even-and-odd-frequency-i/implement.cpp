class Solution {
public:
    int maxDifference(string s) {
        vector<int> v(26);
        for (char c : s) {
            v[c-'a']++;
        }
        int mxOdd = 0, mnEven = 200;
        for (int x : v) {
            if (x == 0) continue;
            if (x % 2) {
                mxOdd = max(mxOdd, x);
            } else {
                mnEven = min(mnEven, x);
            }
        }
        return mxOdd - mnEven;
    }
};