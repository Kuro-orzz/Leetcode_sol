class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int case1 = 0, case2 = 0;
        // case1: 1010..
        // case2: 0101..
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (s[i] == '0') case1++;
                else case2++;
            } else {
                if (s[i] == '0') case2++;
                else case1++;
            }
        }
        int ans = min(case1, case2);
        if (n % 2 == 0) return ans;
        // type1 check
        for (int i = 0; i < n; i++) {
            swap(case1, case2);
            if (s[i] == '0') {
                case1++; case2--;
            } else {
                case1--; case2++;
            }
            ans = min({ans, case1, case2});
        }
        return ans;
    }
};