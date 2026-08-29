class Solution {
public:
    vector<int> balanced_num, used;

    bool isValid() {
        for (int i = 1; i <= 6; i++) {
            if (used[i] && used[i] != i) return false;
        }
        return true;
    }

    void gen_balanced_num(string cur = "") {
        if (cur.size() == 7) return;
        if (cur != "" && isValid()) balanced_num.push_back(stoi(cur));
        for (int i = 1; i <= 6; i++) {
            used[i]++;
            gen_balanced_num(cur + char(i + '0'));
            used[i]--;
        }
    }

    int nextBeautifulNumber(int n) {
        used.resize(7);
        gen_balanced_num();
        balanced_num.push_back(1224444);
        sort(balanced_num.begin(), balanced_num.end());
        return *upper_bound(balanced_num.begin(), balanced_num.end(), n);
    }
};