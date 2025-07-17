class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);

        int i = 0;
        while (i < (int)s.size() && s[i] == '9') i++;
        string mxVal = s;
        for (char &c : mxVal) {
            if (c == s[i]) c = '9';
        }

        int j = 0;
        char t = '0';
        while (j < (int)s.size()) {
            if (!j && s[j] != '1') {
                t = '1';
                break;
            }
            if (j && s[j] != '0' && s[j] != s[0]) {
                t = '0';
                break;
            }
            j++;
        }
        // even j == s.size() not cause error cuz s[j] == '\0'
        string mnVal = s;
        for (char &c : mnVal) {
            if (c == s[j]) c = t;
        }
        return stoi(mxVal) - stoi(mnVal);
    }

    int maxDiff(int num) {
        return minMaxDifference(num);
    }
};