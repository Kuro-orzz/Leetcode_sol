class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                int hourOn = __builtin_popcount(i);
                int minuteOn = __builtin_popcount(j);
                if (hourOn + minuteOn == turnedOn) {
                    string s = to_string(i) + ":" + (j < 10 ? "0" : "") + to_string(j);
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
};