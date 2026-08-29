class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            int tmp = i;
            bool check = true;
            while (tmp) {
                if (tmp % 10 == 0 || i % (tmp % 10)) {
                    check = false;
                    break;
                }
                tmp /= 10;
            }
            if (check) ans.push_back(i);
        }
        return ans;
    }
};