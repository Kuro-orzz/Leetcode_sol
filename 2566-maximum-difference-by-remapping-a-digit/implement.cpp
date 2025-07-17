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
        string mnVal = s;
        for (char &c : mnVal) {
            if (c == s[0]) c = '0';
        }
        return stoi(mxVal) - stoi(mnVal);
    }
};