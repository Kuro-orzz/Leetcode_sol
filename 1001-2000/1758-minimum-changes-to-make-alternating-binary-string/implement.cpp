class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int case1 = 0, case2 = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (s[i] == '0') case1++;
                else case2++;
            } else {
                if (s[i] == '0') case2++;
                else case1++;
            }
        }
        return min(case1, case2);
    }
};