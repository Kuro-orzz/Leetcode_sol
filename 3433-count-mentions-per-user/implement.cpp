class Solution {
public:
    static bool cmp(vector<string> &a, vector<string> &b) {
        if (a[1] != b[1]) return stoi(a[1]) < stoi(b[1]);
        if (a[0] == "MESSAGE" && b[0] == "OFFLINE") return false;
        return true;
    }

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int n = numberOfUsers;
        int m = events.size();
        sort(events.begin(), events.end(), cmp);
        vector<int> timeOn(n, 0), ans(n, 0);
        for (int i = 0; i < m; i++) {
            if (events[i][0] == "MESSAGE") {
                int timestamp = stoi(events[i][1]);
                if (events[i][2] == "ALL") {
                    for (int id = 0; id < n; id++) ans[id]++;
                } else if (events[i][2] == "HERE") {
                    for (int id = 0; id < n; id++) {
                        if (timestamp >= timeOn[id]) ans[id]++;
                    }
                } else {
                    stringstream ss(events[i][2]);
                    string s;
                    while (ss >> s) {
                        int id = stoi(s.substr(2));
                        ans[id]++;
                    }
                }
            } else if (events[i][0] == "OFFLINE") {
                int timestamp = stoi(events[i][1]);
                int id = stoi(events[i][2]);
                timeOn[id] = max(timeOn[id], timestamp + 60);
            }
        }
        return ans;
    }
};