class Solution {
public:
    int concat(int a, int b, int c) {
        return a * 100 + b * 10 + c;
    }

    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;   
        for (int i = 0; i < digits.size(); i++) {
            for (int j = i + 1; j < digits.size(); j++) {
                for (int k = j + 1; k < digits.size(); k++) {
                    if (digits[i] != 0) {
                        if (digits[k] % 2 == 0)
                            ans.push_back(concat(digits[i], digits[j], digits[k]));
                        if (digits[j] % 2 == 0)
                            ans.push_back(concat(digits[i], digits[k], digits[j]));
                    }
                    if (digits[j] != 0) {
                        if (digits[k] % 2 == 0)
                            ans.push_back(concat(digits[j], digits[i], digits[k]));
                        if (digits[i] % 2 == 0)
                            ans.push_back(concat(digits[j], digits[k], digits[i]));
                    }
                    if (digits[k] != 0) {
                        if (digits[j] % 2 == 0)
                            ans.push_back(concat(digits[k], digits[i], digits[j]));
                        if (digits[i] % 2 == 0)
                            ans.push_back(concat(digits[k], digits[j], digits[i]));
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};